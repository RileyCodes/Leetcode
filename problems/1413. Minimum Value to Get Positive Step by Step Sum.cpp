class Solution {
public:
    int minStartValue(vector<int>& nums) {
        
        int localMin = nums[0];
        
        
        int sum = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            sum += nums[i];
            localMin = min(localMin, sum);
        }
        
        
        return localMin < 0 ? (-localMin) + 1: 1;
    }
};