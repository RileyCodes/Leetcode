class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        for(int i = 0;i<nums.size();i++)
        {
             if(nums[i]==0) 
             {
                 k++;
             }
            else 
             {
                 swap(nums[i],nums[i-k]);
             }
        }
    }
};  