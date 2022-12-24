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
    
    
    void in_order(TreeNode* node, vector<int>& lst)
    {
        if(node == nullptr)
            return;
        
        in_order(node->left,lst);
        lst.emplace_back(node->val);
        in_order(node->right,lst);
    }
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> ordered;
        in_order(root,ordered);
        
        int lP = 0,rP = ordered.size() - 1;
        while(lP < rP)
        {
            if(ordered[lP] + ordered[rP] < k)
                ++lP;
            else if (ordered[lP] + ordered[rP] > k) 
                --rP;
            else return true;
        }
        
        return false;
    }
};