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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* div = nullptr;
        q.push(div);
        
        int depth = 0;
        if(root == nullptr)
            return depth;
        
        while(!q.empty())
        {
            auto* node = q.front();
            q.pop();
            
            if(node == div)
            {
                ++depth;
                q.push(div);
                if(q.front() == div)
                    return depth;
                continue;
            }
            
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
            if(!node->left && !node->right)
                return depth + 1;
            
        }
        return depth;
    }
};