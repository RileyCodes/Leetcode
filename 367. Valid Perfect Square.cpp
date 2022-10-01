class Solution {
public:
    bool isPerfectSquare(int num) {
        long long lP = 2, rP = num;
        if(num == 1)
            return true;
        while(lP <= rP)
        {
            long long mid = (lP + rP) / 2;
            long long x = mid * mid;
            if(x == num)
            {
                return true;
            }
            else if(x < num)
            {
                lP = mid + 1;
            }
            else
            {
                rP = mid - 1;
            }
        }
        return false;
    }
};