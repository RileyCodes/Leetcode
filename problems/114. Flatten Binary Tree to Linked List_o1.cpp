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

    TreeNode* recur(TreeNode* node)
    {
        TreeNode *resLeft = nullptr, *resRight = nullptr;
        resLeft = node->left? recur(node->left) : node;
        resRight = node->right? recur(node->right) : resLeft;

        if(resLeft)
        {
            TreeNode* right = node->right;
            node->right = node->left;
            if(resRight != node)
                resLeft->right = right;
                
            node->left = nullptr;
        }

        return resRight;
    }

    void flatten(TreeNode* root)
    {
        cout <<"start" << endl;
        if(!root)
            return;
        recur(root);
    }
};