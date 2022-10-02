class Solution {
public:
    bool isPowerOfFour(int n) {
        int pow = 1;
        
        while(pow < n)
        {
            if(INT_MAX / 4 < pow)
                return false;
            pow *= 4;
        }
        
        return pow == n;
    }
};