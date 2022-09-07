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
public:
    
    int iMaxDepth = 0;
    
    void inorder(int depth, TreeNode* node)
    {
        if(node == nullptr)
            return;
        
        iMaxDepth = max(iMaxDepth,depth);
        
        inorder(depth + 1, node->left);
        inorder(depth + 1, node->right);
    }
    
    
    int maxDepth(TreeNode* root) {
        inorder(1,root);
        return iMaxDepth;
    }
};