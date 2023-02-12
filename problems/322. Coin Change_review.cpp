class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;
            
        vector<int> dp(amount + 1);
        for(int i = 1; i <= amount; ++i)
        {
            for(auto&& coin : coins)
            {
                if(i - coin >= 0)
                {
                    if(i - coin == 0 || dp[i - coin] != 0)
                    {
                        if(dp[i] == 0)
                            dp[i] = 1 + dp[i - coin];
                        else
                            dp[i] = min(dp[i], 1 + dp[i - coin]);
                    }
                }
            }
        }
        return dp[amount] == 0? -1 : dp[amount];
    }
};