/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

public:

    bool IsExist(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == nullptr)
            return false;
        if(root->left == p || root->left == q)
            return true;
        if(root->right == p || root->right == q)
            return true;            
        if(IsExist(root->left, p, q))
            return true;
        if(IsExist(root->right,p, q))
            return true;
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr)
            return nullptr;
        if((root->left == p || root->left == q) && (root->right == p || root->right == q))
            return root;
        if(root == p)
            return p;
        if(root == q)
            return q;

        if(root->left == p || root->left == q)
        {
            if(IsExist(root->left, p , q))
                return root->left;
            else if(IsExist(root->right, p , q))
                return root;
        }
        else if(root->right == p || root->right == q)
        {
            if(IsExist(root->right, p , q))
                return root->right;
            else if(IsExist(root->right, p , q))
                return root;            
        }
        
        auto* lP = lowestCommonAncestor(root->left, p, q);
        auto* rP = lowestCommonAncestor(root->right, p, q);
        if(lP && rP)
            return root;
        
        return lP? lP : rP;
    }
};