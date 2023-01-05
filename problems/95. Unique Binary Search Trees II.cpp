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

    vector<TreeNode*> recur(int lo, int hi)
    {
        if(lo > hi)
            return vector<TreeNode*>(1);
            
        vector<TreeNode*> ans;
        for(int i = lo; i <= hi; ++i)
        {
            vector<TreeNode*> leftTree = recur(lo, i - 1);
            vector<TreeNode*> rightTree = recur(i + 1, hi);

            for(auto&& left : leftTree)
            {
                for(auto&& right : rightTree)
                {

                    auto* root = new TreeNode(i);
                    root->left =  left;
                    root->right = right;
                    ans.emplace_back(root);
                }
            }
        }

        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        return recur(1, n);
    }
};