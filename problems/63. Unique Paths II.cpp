class Solution {
public:
    /*
    动态规划： 最后一步 -> 更小规模子问题 -> 状态转移方程 -> 初值/边界条件
    
    最后一步：和Unique Paths I一样，我们的最后一步仍然是从目标的左边或者上边来的
    但是如果有障碍物，那么我们应该认为只有0个办法从这里过来。 
    并且别忘了因为机器人只能往右或者往下走，所以对于第一行或者第一列，障碍物后面都是不可达的！
    
    更小规模子问题：抵达目的地的左边/上面有几个办法？（如果是障碍物，或者越界，那么就是0个）
    
    状态转移方程:f[m-1,n-1] = (IsRock)? 0 : (IsOutbound? 0 : f[m-2,n-1]) + (IsOutbound? 0 : f[m-1,n-2])
    
    初值：f[0][0] = !obstacleGrid[0][0];
    */
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int f[obstacleGrid.size()][obstacleGrid[0].size()];
        
        f[0][0] = !obstacleGrid[0][0];
        for(int i = 0; i < obstacleGrid.size(); ++i)
        {
            for(int j = 0; j < obstacleGrid[0].size(); ++j)
            {
                if(i == 0 && j == 0)
                    continue;
                
                f[i][j] = obstacleGrid[i][j] ? 0 : 
                (((i - 1) < 0) ? 0 :  f[i - 1][j]) + 
                    (((j - 1) < 0) ? 0 : f[i][j - 1]);
            }
        }
        return f[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
        
    }
};