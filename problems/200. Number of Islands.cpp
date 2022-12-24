class Solution {
public:
    
    /*
    这道题要我们计算出岛屿的数量，和我们以前计算出每个岛屿的面积是类似的思路
    我们可以用深度优先搜索和visited数组，visited数组用来避免遍历已经跑过的坐标
    */
    
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited,int x,int y)
    {
        if(visited[x][y])//已经被访问过了，跳出。
            return;
        
        visited[x][y] = true;//不是陆地应该记录下来，免得反复判断？
        
        if(grid[x][y] == '0')//不是陆地，跳出。
            return;        
        
        const int direction_x[4]{-1,1,0,0};
        const int direction_y[4]{0,0,1,-1};
        
        //上下左右都跑一遍，但是前提是不越界和没看过（没看过会调用以后返回）
        for(int i = 0; i < 4; ++i)
        {
            int next_x = x + direction_x[i];
            int next_y = y + direction_y[i];
            if(next_x < 0 || next_x >= grid.size() ||
              next_y < 0 || next_y >= grid[0].size())
                continue;
            
            dfs(grid, visited ,next_x ,next_y);
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        vector<vector<int>> visited(grid.size(), vector<int> (grid[0].size(), 0));
        int islandCount = 0;
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                //如果这个单元被访问过了，唯一的可能就是被之前的DFS标记到另一个岛屿上了。
                //如果是海，直接跳过。 对于每个新发现的陆地开一个dfs进程去把整个岛屿标记起来。
                if(visited[i][j] || grid[i][j] == '0')
                    continue;
                
                //因此，在这边每次发现一个没访问过的单元都意味着发现了一个新的岛屿。
                ++islandCount;
                dfs(grid,visited,i,j);
            }
        }
        return islandCount;
    }
};