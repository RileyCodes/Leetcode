class Solution {
public:

    int daysNeededByCapacity(int capacity, vector<int>& weights,int max_days)
    {
        int cur_capacity = capacity;
        int day = 1;
        for(auto&& weight : weights)
        {
            if(cur_capacity - weight < 0)
            {
                cur_capacity = capacity;
                ++day;
                if(day > max_days)
                    return INT_MAX;
            }
            cur_capacity -= weight;
            
        }
        return day;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int minShip = weights[0];
        int maxShip = 0;
        for(auto&& weight : weights)
        {
            minShip = minShip < weight ? weight : minShip;
            maxShip += weight;
        }
        ++maxShip;
        int ans = INT_MAX;
        while(minShip < maxShip)
        {
            int mid = (minShip + maxShip) / 2;  
            int res = daysNeededByCapacity(mid,weights,days);
            if(res <= days)
            {
                ans = min(ans, mid);
                maxShip = mid;
            }
            else if(res > days)
            {
                minShip = mid + 1;
            }
        }
        return ans;
    }
};