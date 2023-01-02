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

    int recur(TreeNode* node, int sumFromRight = 0)
    {
        if(node == nullptr)
            return 0;
        int tmp = sumFromRight;
        sumFromRight += recur(node->right, sumFromRight);            
        node->val += sumFromRight;
        if(node->right != nullptr)
            node->val -= tmp;
        return max(recur(node->left, node->val), node->val);
    }

    TreeNode* bstToGst(TreeNode* root) {
        recur(root, 0);
        return root;
    }
};