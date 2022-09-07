class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
        
        int lastInt = nums[0];
        
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] != lastInt)
            {
                nums[count++] = nums[i];
                lastInt = nums[i];
            }
        }
        return count;
    }
};