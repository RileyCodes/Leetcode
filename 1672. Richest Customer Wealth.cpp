class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;
        
        for(int i = 0; i < accounts.size(); ++i)
        {
            int rowSum = 0;
            for(int j = 0; j < accounts[0].size(); ++j)
            {
                rowSum += accounts[i][j];
            }
            maxWealth = max(rowSum,maxWealth);
        }
        
        return maxWealth;
    }
};