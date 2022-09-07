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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr)
            return root;
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty())
        {
            auto* node = q.front();
            q.pop();
            if(node->left != nullptr)
                q.push(node->left);
            
            if(node->right != nullptr)
                q.push(node->right);
            
            auto* tmp = node->left;
            node->left = node->right;
            node->right = tmp;
        }
        return root;
    }
};