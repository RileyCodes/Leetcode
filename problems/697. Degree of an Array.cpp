class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int hash[50000][3]{0};
        int maxDeg = 0;
        
        for(int i = 0 ; i < nums.size(); ++i)
        {
            ++hash[nums[i]][0];
            if(hash[nums[i]][0] == 1)
            {
                hash[nums[i]][1] = i;
            }
            else
            {
                hash[nums[i]][2] = i;
            }
            maxDeg = max(hash[nums[i]][0],maxDeg);
        }
        
        int minWidth = 50000;
        for(int i = 0 ; i < 50000; ++i)
        {
            if(hash[i][0] == maxDeg)
            {
                if(minWidth,hash[i][2] == 0)
                    minWidth = min(1,minWidth);
                else
                    minWidth = min(minWidth,hash[i][2] - hash[i][1] + 1);
            }
        }
        
        return minWidth;
    }
};