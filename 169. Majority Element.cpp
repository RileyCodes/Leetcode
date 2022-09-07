class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int currentNum = nums[0];
        int count = 1;
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] != currentNum)
            {
                --count;
                if(count == 0)
                {
                    currentNum = nums[i];
                    count = 1;
                }
            }
            else
                ++count;
        }
        return currentNum;
    }
};