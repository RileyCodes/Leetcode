class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int lastEven;
        int count = 0;
        sort(nums.begin(),nums.end());
        int maxCount = 0;
        int ans = -1;
        
        bool isFirst = true;
        for(int i = nums.size() - 1; i >= 0; --i)
        {
            if(nums[i] % 2 == 0)
            {
                if(isFirst)
                {
                    isFirst = false;
                    lastEven = nums[i];
                }
                
                if(lastEven == nums[i])
                {
                    ++count;
                }
                else
                {
                    count = 1;
                }
                if(count >= maxCount)
                {
                    ans = nums[i];
                    maxCount = count;
                }                
                lastEven = nums[i];
            }
        }
        return ans;
    }
};