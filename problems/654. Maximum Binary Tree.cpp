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

    TreeNode* recur(vector<int>& nums, int start, int end)
    {
        if(start > end)
            return nullptr;
        int maxNum = INT_MIN;
        int maxAt = -1;
        for(int i = start; i <= end; ++i)
        {
            if(maxNum < nums[i])
            {
                maxNum = nums[i];
                maxAt = i;
            }
        }

        auto* node = new TreeNode(maxNum);
        node->left = recur(nums, start, maxAt - 1);
        node->right = recur(nums, maxAt + 1, end);

        return node;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int maxNum = INT_MIN;
        int maxAt = -1;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(maxNum < nums[i])
            {
                maxNum = nums[i];
                maxAt = i;
            }
        }
        auto* root = new TreeNode(maxNum);
        root->left = recur(nums,0, maxAt - 1);
        root->right = recur(nums, maxAt + 1, nums.size() - 1);
        return root;
    }
};