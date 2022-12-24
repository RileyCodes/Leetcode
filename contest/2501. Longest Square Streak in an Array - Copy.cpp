class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        
        set<long long> s;
        int globalMax = -1;
        
        for(auto num : nums)
        {
            s.insert(num);
        }
        
        for(auto num : s)
        {
            int localMax = 1;
            while(1)
            {
                if(s.count(num * num))
                {
                    ++localMax;
                }
                else
                    break;
                num = num * num;
            }
            if(localMax > 1)
                globalMax = max(globalMax, localMax);
        }
        return globalMax;
    }
};