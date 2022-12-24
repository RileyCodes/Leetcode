class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(nums.size());
        
        
        int index = 0;
        for(int i = 0; i < nums.size(); i += 2)
        {
            ans[i] = nums[index++];
        }
        
        index = nums.size() / 2;
        for(int i = 1; i < nums.size(); i += 2)
        {
            ans[i] = nums[index++];
        }
        
        return ans;
    }
};