class Solution {
public:
    int mySqrt(int num) {
        if(num <= 1)
            return num;
        
        int ans = 0;
        long long lP = 1, rP = (long long)num + 1;
        
        long long mid;
        while(lP < rP)
        {
            mid = (lP + rP) / 2;
            long long x = mid * mid;
            if(x <= num)
            {
                ans = mid;
                lP = mid + 1;
            }
            else
                rP = mid;
                
        }
        return ans;
    }
};