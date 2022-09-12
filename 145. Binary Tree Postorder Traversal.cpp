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
    
    void postOrder(vector<int>& v,TreeNode* node)
    {
        if(node == nullptr)
            return;
        postOrder(v,node->left);
        postOrder(v,node->right);        
        v.emplace_back(node->val);
    }
    

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postOrder(ans,root);
        return ans;        
    }
};