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
    
    //[-10,-3,0,5,9]
    //[-10,-3,|0|,5,9]
    
    //[-10,-3,|0|,5,9]
    TreeNode* getMidNode(int start,int end, const vector<int>& nums)
    {
        //cout << "index " << index << " end " << end << endl;
        if((end < start))
            return nullptr;
        if(end >= nums.size())
            return nullptr;
        
        int mid = start + ((end - start) / 2);
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = getMidNode(start,mid - 1,nums);
        node->right = getMidNode(mid + 1,end,nums);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        

        /*
        TreeNode* left = new TreeNode(nums[mid / 2]);
        TreeNode* right = new TreeNode(nums[mid + ((nums.size() - mid)/ 2)]);
        root->left = left;
        root->right = right;
        */
        
        return getMidNode(0, nums.size() - 1, nums);
    }
};