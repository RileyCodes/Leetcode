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
    
    int recur(TreeNode* node)
    {
        if(node == nullptr)
            return 0;
        
        int leftHeight = recur(node->left);
        int rightHeight = recur(node->right);
        
        int diff = leftHeight - rightHeight;
        
        if(leftHeight == -1 || rightHeight == -1 || diff > 1 || diff < -1)
            return -1;
        
        return max(leftHeight,rightHeight) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;
        
        return recur(root) >= 0;
    }
};