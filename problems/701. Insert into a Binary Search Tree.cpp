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

    bool insert(TreeNode* node, int val, int valMin = -1, int valMax = -1)
    {
        if(node == nullptr)
            return false;
        if(node->left == nullptr && val < node->val && (valMin == -1 || valMin < val ))
        {
            node->left = new TreeNode(val);
            return true;
        }
        else if(node->right == nullptr && val > node->val && (valMax == -1 || val < valMax))
        {
            node->right = new TreeNode(val);
            return true;           
        }
        if(insert(node->left, val, valMin, node->val))
            return true;
        if(insert(node->right, val, node->val, valMax))
            return true;
        return false;
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr)
            return new TreeNode(val);
        insert(root, val);
        return root;
    }
};