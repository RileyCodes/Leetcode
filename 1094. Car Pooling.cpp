class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int joined[1001]{0};

        for(auto&& trip : trips)
        {
            joined[trip[1]] += trip[0];
            joined[trip[2]] -= trip[0];
        }
        if(joined[0] > capacity)
            return false;
        for(int i = 1; i < 1001; ++i)
        {
            joined[i] += joined[i - 1];
            if(joined[i] > capacity)
                return false;
        }
    
        return true;    
    }
};