class Solution {
public:

    int eat(vector<int> & piles, int h, int k)
    {
        int hoursSpent = 0;
        for(auto&& pile : piles)
        {
            //10 - 1 / 10 = (9 / 10) =  0 + 1 = 1
            //11 - 1 = 10 / 10 = 1 + 1  = 2            
            int hour = ((pile - 1) / k) + 1;
            hoursSpent += hour;
            if(hoursSpent > h)
                return INT_MAX;
        }
        return hoursSpent;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int lP = 1, rP = 0;

        for(auto&& pile : piles)
            rP = max(rP , pile);
        ++rP;
        int ans = INT_MAX;
        while(lP < rP)
        {
            int mid = (lP + rP) / 2;
            int hrSp = eat(piles, h, mid);
            if(hrSp <= h)
            {
                ans = min(ans,mid);
                rP = mid;
            }
            else if(hrSp > h)
            {
                lP = mid + 1;
            }
        }
        return ans;
    }
};