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

class Solution {
    
    void _visit(Node* node, Node* parent,bool isLeft)
    {
        if(node == nullptr)
            return;
        if(parent == nullptr)
            node->next = nullptr;
        else if(isLeft)
            node->next = parent->right;
        else
            node->next = (parent->next == nullptr)? nullptr : parent->next->left;
            

        if(!node->left)
            return;
        
        _visit(node->left,node,true);
        _visit(node->right,node,false);
        
    }
public:
    Node* connect(Node* root) {
        _visit(root,nullptr,false);
        return root;
    }
};