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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)
            return nullptr;
        if(root->val == key)
        {
            if(root->left == nullptr)
            {
                return root->right;
            }
            if(root->right == nullptr)
                return root->left;


            //Find greatest node from right side.
            TreeNode* node = root->left;
            while(node && node->right)
                node = node->right;

            deleteNode(root, node->val);

            node->left =  root->left;  
            node->right = root->right;    

            return node;
        }
        else if(key > root->val)
            root->right = deleteNode(root->right, key);
        else 
            root->left = deleteNode(root->left, key);
        
        return root;
    }
};
