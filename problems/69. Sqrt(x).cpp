class Solution {
public:
    int mySqrt(int x) {
        int small = 0, large = x;
        int mid = 0;
        int ans = -1;
        
        while(small <= large)
        {
            mid = (small + large) / 2;

            if((long long)mid * mid <= x)
            {
                ans = mid;
                small = mid + 1;                
            }
            else
            {
                large = mid - 1;
            }
        }
        return ans;
    }
};