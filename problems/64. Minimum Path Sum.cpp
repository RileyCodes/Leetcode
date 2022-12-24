class Solution {
public:
    
    /*
        这道题可以思考每一步都必然来自于左或者上
        状态转移方程：
        设f[x,y]是从f[0,0]走到f[x,y]的最优解
        
        那么f[x,y] = min(f[x - 1,y],f[x,y - 1]) + grid[x][y]
        也就是说最优解必然是从上面下来的最优解，或者左边过来的最优解，加上本格的开销。
        

    */
    int minPathSum(vector<vector<int>>& grid) {
        int f[grid[0].size()][grid.size()];
        f[0][0] = grid[0][0];
        
        for(int i = 0 ; i < grid[0].size(); ++i)
        {
            for(int j = 0; j < grid.size(); ++j)
            {
                if(i == 0 && j == 0)
                    continue;

                //因为必然是可达的，如果其中一个方向越界了，肯定就只能从另一个方向来。
                if(i - 1 < 0)
                    f[i][j] = f[i][j - 1];
                else if(j - 1 < 0)
                    f[i][j] = f[i - 1][j];
                else
                    f[i][j] = min(f[i][j - 1],f[i - 1][j]);//两个方向都可行的时候，就要看哪边成本最小了
                
                f[i][j] += grid[j][i];
                
            }
        }
        
        return f[grid[0].size() - 1][grid.size() - 1];
    }
};