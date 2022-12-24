/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
    int maxWidth = 0;
public:
    
    /*
        inorder会不断的往下搜索，直到遇到nullptr。 我们不需要使用depth变量在每次调用inorder的时候增加递归深度，这是因为当遇到nullptr的时候，我们返回了0，然后从非nullptr的时候再次返回的时候，我们就返回了max(maxL,maxR) + 1
        
        这里的 +1 确保了每次我们从树的底部向上走的时候，高度增加了一个
         max(maxL,maxR) 确保了我们每个节点向上走的时候，往上返回的都是该节点下最长路径
         
         因为使用了postorder，我们可以确保每个root节点被处理的时候（具体来说，我们的处理是maxWidth = max(maxWidth, maxL + maxR);）
         被处理的时候都已经完成了对其下面的所有左右子节点的访问。因此，当执行max(maxWidth, maxL + maxR)
         我们已经明确知道该节点的左右子节点的最大深度。
         
         因为深度刚好等于边长，所以我们不需要做任何加减操作（这样想象一下，每次递归返回的时候，你都穿过了一个边，从第n级返回到了第n减1级，所以路径上边的数量等于你递归深度。
         
         而宽度信息，自然就是每个子节点下左右深度相加的结果，因为我们只需要知道最大宽度，因此只需要一个成员变量保存最大值就行，递归返回的时候只需要返回每个节点下的最大深度，以供上一级节点判断即可。
         
        
    */
    int postorder(TreeNode* node)
    {
        if(node == nullptr)
            return 0;
        int maxL = postorder(node->left);
        int maxR = postorder(node->right);
        maxWidth = max(maxWidth, maxL + maxR);
        return max(maxL,maxR) + 1;
    }
    

    
        
    int diameterOfBinaryTree(TreeNode* root) {
        postorder(root);
        return maxWidth;
    }
};