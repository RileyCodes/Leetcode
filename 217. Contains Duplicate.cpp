class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int lastNum = nums[0];
        for(int i = 1; i < nums.size(); ++i)\
        {
            if(nums[i] == lastNum)
                return true;
            else
                lastNum = nums[i];
        }
        return false;
    }
};