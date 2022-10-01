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
    vector<TreeNode*> nodes;
    
    void inorder(TreeNode* node)
    {
        if(node == nullptr)
            return;
        inorder(node->left);
        nodes.emplace_back(node);
        inorder(node->right);
    }
    

    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        
        for(int i = 1; i < nodes.size(); ++i)
        {
            nodes[i - 1]->right = nodes[i];
            nodes[i - 1]->left = nullptr;
        }
        nodes[nodes.size() - 1]->left = nullptr;
        return nodes[0];
    }
};