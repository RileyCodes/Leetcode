class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        
        if(prices.size() < 2)
            return profit;        
        for(int i = 1; i < prices.size(); ++i)
        {
            int diff = prices[i] - prices[i - 1];
            if(diff > 0)
                profit += diff;
        }
        return profit;
    }
};