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
    
    int inorder(TreeNode* node,int& k)
    {
        if(node == nullptr)
            return -1;
        
        int res = inorder(node->left, k);
        if(k == 1)   
            return res == -1? node->val : res;
        --k;

        int res2 = inorder(node->right, k);
        return res == -1 ? res2 : res;
    }

    int kthSmallest(TreeNode* root, int k) {
        return inorder(root, k);
    }
};