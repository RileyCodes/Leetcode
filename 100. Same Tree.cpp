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
    
    
    bool isSame(TreeNode* a, TreeNode* b)
    {
        if((a && !b) || (!a && b))
            return false;    
      
        if(!a && !b)
            return true;   

        if(a->val != b->val)
            return false;        
        
        return isSame(a->left,b->left) && isSame(a->right,b->right);
        
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isSame(p,q);
    }
};