/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/


/*
这道题需要把同一级的节点的next指针连接到本级的下一个（右边）节点，如果已经是最右边了，那么就连接到null。

2和3在同一级，2链接到3，3链接到null
4 5 7在同一级，由于没有6，5直接链接到7.

可以发现，如果我们每次在第n级的位置处理n+1级的数据的话，会发现this->left->next = this->right
而this->right = this->next->left == nullptr? this->next->left : this->next->right.

我们可以用一个双重循环处理每个子树，一个外循环始终cur = this-> left
一个内循环走this->next
*/
class Solution {
public:
    

    
    Node* GetLeftmostChildNode(Node *parent)
    {
        Node* leftmost = nullptr;
        while(parent && leftmost == nullptr)//如果还没做到最左边的节点，而当前我们还有父节点没看
        {
            leftmost = parent->left? parent->left : parent->right;//最左边没有就取最右边，如果也没有，自然就是null
            //把当前父节点移到同级右边哪个，如果还是null，就要在下一轮循环看右边的父节点的左右子节点能不能用。
            parent = parent->next;
        }
        return leftmost;
    }
    Node* connect(Node* root) {
        
        Node* leftNode = root;
        while(leftNode)
        {
            Node* cur = leftNode;
            while(cur)
            {
                if(cur->left)//如果本子树存在左子节点
                {
                    if(cur->right)//如果有右子节点，那么左子节点的next就是右子节点
                        cur->left->next = cur->right;
                    else 
                        cur->left->next = GetLeftmostChildNode(cur->next);         
                }
                if(cur->right)//如果本子树存在右子节点
                    cur->right->next = GetLeftmostChildNode(cur->next); 
                cur = cur->next;
            }

            //不是完美二叉树，有时候最左边可能没东西，但是下一级其实有节点，这种情况要从左到右扫一遍
            leftNode = GetLeftmostChildNode(leftNode);
        }
        
        return root;
    }
};