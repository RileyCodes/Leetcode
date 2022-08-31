class Solution {
public:
    /*

     状态转移方程：
     f[n,0] = min(costs[n][1],costs[n][2]) + min(f[n,1],f[n,2])
     f[n,1] = min(costs[n][0],costs[n][2]) + min(f[n,0],f[n,2])
     f[n,2] = min(costs[n][0],costs[n][1]) + min(f[n,0],f[n,1])


    初始值：
    f[0,0] = costs[0][0];
    f[0,1] = costs[0][1];
    f[0,2] = costs[0][2];


     */


    int minCost(vector<vector<int>> &costs) {
        if(costs.size() == 0)
            return 0;

        int f[costs.size()][3];

        f[0][0] = costs[0][0];
        f[0][1] = costs[0][1];
        f[0][2] = costs[0][2];

        for(int i = 1; i < costs.size(); ++i)
        {
            f[i][0] = costs[i][0] + min(f[i - 1][1],f[i - 1][2]);
            f[i][1] = costs[i][1] + min(f[i - 1][0],f[i - 1][2]);
            f[i][2] = costs[i][2] + min(f[i - 1][0],f[i - 1][1]);
        }

        return min(min(f[costs.size() - 1][0],f[costs.size() - 1][1]),f[costs.size() - 1][2]);
    }
};