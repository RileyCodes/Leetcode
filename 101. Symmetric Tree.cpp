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
    
    void preorder_left(string& s, TreeNode* node)
    {
        if(node == nullptr)
        {
            s += "#";
            return;
        }
        
        s += node->val + 48;
        preorder_left(s, node->left);
        preorder_left(s, node->right);
    }
    
    void preorder_right(string& s, TreeNode* node)
    {
        if(node == nullptr)
        {
            s += "#";
            return;
        }
        
        s += node->val + 48;
        preorder_right(s, node->right);
        preorder_right(s, node->left);
    }
        
    
    bool isSymmetric(TreeNode* root) {
        string sLeft,sRight;
        preorder_left(sLeft,root->left);
        preorder_right(sRight,root->right);
        cout << sLeft << endl << sRight << endl;
        return sLeft == sRight;
    }
};