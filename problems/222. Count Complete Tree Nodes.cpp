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
    int countNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;

        int lH = 0, rH = 0;
        auto *left = root, *right = root;
        
        while(left)
        {
            left = left->left;
            ++lH;
        }
        while(right)
        {
            right = right->right;
            ++rH;
        }

        if(lH == rH)
            return (int)pow(2,lH) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};