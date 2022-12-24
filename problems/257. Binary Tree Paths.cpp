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
    
    void recur(vector<string>& paths,TreeNode* node,string path,TreeNode* root)
    {
        if(node == nullptr)
            return;
        
        if(node != root)
            path = path + "->" + to_string(node->val);
        if(node->left != nullptr || node->right != nullptr)
        {
            
            recur(paths,node->left,path,root);
            recur(paths,node->right,path,root);
        }
        else
        {
            paths.emplace_back(path);            
        }
    
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        
        string path = to_string(root->val);
        recur(paths,root,path,root);
        
        return paths;
    }
};