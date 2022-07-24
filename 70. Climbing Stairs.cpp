class Solution {
    int results[46]{};
public:
    int climbStairs(int n) {
        if(n < 0)
            return 0;
        if(n == 0)
            return 1;
        if(results[n] != 0)
            return results[n];
        int result = climbStairs(n - 1) + climbStairs(n - 2);
        results[n] = result;
        return result;
    }
};