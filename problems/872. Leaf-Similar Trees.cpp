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

    

    void recur(TreeNode* node, vector<int>& res)
    {
        if(node == nullptr)
            return;
        recur(node->left, res);
        recur(node->right, res);
        
        if(node->left == nullptr && node->right == nullptr)
        {
            res.emplace_back(node->val);
            cout << node->val << endl;
        }
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> res1 , res2;
        recur(root1,res1);
        recur(root2,res2);
        if(res1.size() != res2.size() )
            return false;

        for(int i = 0; i < res1.size() ; ++i)
        {
            if(res1[i] != res2[i])
                return false;
        }
        return true;
    }
};