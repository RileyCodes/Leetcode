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
    
    bool trysum(TreeNode* node,int sum,int target)
    {
        if(node == nullptr)
            return false;
        
        sum += node->val;
        
        if(sum == target && node->left == nullptr && node->right == nullptr)
        {
            return true;
        }
        
        return trysum(node->left,sum,target) || trysum(node->right,sum,target);
        
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        return trysum(root,0,targetSum);
    }
};