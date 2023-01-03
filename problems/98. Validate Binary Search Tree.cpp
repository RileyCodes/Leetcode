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
    
    bool validateBST(TreeNode* node, int valMin = -1, int valMax = -1)
    {
        if(node == nullptr)
            return true;

        bool isLeftVaild = node->left == nullptr || 
        ((valMin == -1 || valMin < node->left->val) && node->left->val < node->val);

        bool isRightVaild = node->right == nullptr || 
        ((valMax == -1 || valMax > node->right->val) && node->right->val > node->val);

        if(validateBST(node->left, valMin, node->val) && 
        validateBST(node->right, node->val,valMax) &&
        isLeftVaild && isRightVaild)
            return true;      
        return false;  
    }

    bool isValidBST(TreeNode* root) {
        return validateBST(root);
    }
};