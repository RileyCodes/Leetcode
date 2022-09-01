class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
    //如果我们在i卖，那么我们的最大利润是在0到i-1时买入价格的最小值
    //0到2的最小值等于0到1的最小值和2的值取最小，以此类推，是个类似于前缀和的过程。
        int profit = 0;

        int f[2];
        f[0] = prices[0];
        for(int i = 1; i < prices.size(); ++i)
        {
            //f[i]代表了[0,i]之间的最低交易价
            //所以f[i]来自于f[i -1]和prices[i]之间的最低交易价
            //在[i]卖出的利润等于price[i] 减去 f[i - 1]
            
            f[i % 2] = min(f[!(i % 2)],prices[i]);
            profit = max(profit,prices[i] - f[!(i % 2)]);
        }
        return profit;
    }
};