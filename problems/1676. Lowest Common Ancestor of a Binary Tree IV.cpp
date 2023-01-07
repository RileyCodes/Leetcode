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

    int recur(TreeNode* root,  set<TreeNode*> &nodes, TreeNode*& result)
    {
        if(root == nullptr)
            return 0;

        int count = recur(root->left, nodes, result);
        count += recur(root->right, nodes, result);
        count += nodes.count(root);
        //cout << "count " << count << " at " << root->val << endl;
        if(count == nodes.size() && !result)
            result = root;
        
        return count;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {

        set<TreeNode*> s;
        for(auto&& node : nodes)
            s.insert(node);
        TreeNode* ans = nullptr; 
        recur(root, s, ans);
        return ans;
    }
};