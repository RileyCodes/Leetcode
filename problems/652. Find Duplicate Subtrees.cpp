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

    set<string> st;
    set<string> ans_st;

    string recur(TreeNode* node, vector<TreeNode*>& ans)
    {
        if(node == nullptr)
            return "#";

        string hash = recur(node->left, ans);
        hash += recur(node->right, ans);
        hash += to_string(node->val);
        hash += ",";

        if(st.count(hash) && ans_st.count(hash) == 0)
        {
            
            ans_st.insert(hash);
            ans.emplace_back(node);
        }
            
        else
            st.insert(hash);
        
        return hash;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        
        
        string hash = recur(root->left, ans);
        hash += recur(root->right, ans);
        hash += to_string(root->val);
        hash += ",";
        if(st.count(hash) && ans_st.count(hash) == 0)
        {
            ans_st.insert(hash);
            ans.emplace_back(root);
        }
        else
            st.insert(hash);

        return ans;
    }
};