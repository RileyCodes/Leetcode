class Solution {
    int dfs(bool** visited, vector<vector<int>>& grid, int i, int j)
    {
        const int x_direct[4] = {-1,1,0,0};
        const int y_direct[4] = {0,0,-1,1};
        
        int nodeFound = 0;
        
        if(visited[i][j] == false)
        {
            ++nodeFound;
            visited[i][j] = true;   
        }
        for(int k=0; k < 4; k++)
        {
            int x = i + x_direct[k];
            int y = j + y_direct[k];
            if(x >= 0 && x < grid.size() &&
              y >= 0 && y < grid[0].size() &&
               visited[x][y] == false &&
               grid[x][y] == 1
              )
            {
                ++nodeFound;
                visited[x][y] = true;
                nodeFound += dfs(visited, grid, x,y);
            }
        }
        return nodeFound;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        bool visited[grid.size()][grid[0].size()];
        int maxArea = 0;
        for(int i=0; i < grid.size(); i++)
        {
            for(int j=0; j < grid[0].size(); j++)
            {
                visited[i][j] = false;
            }
        }
        
        bool* pVisited[grid.size()];
        for(size_t i =0 ; i < grid.size() ; ++i)
        {
            pVisited[i] = visited[i];
        }
        
        for(int i=0; i < grid.size(); i++)
        {
            for(int j=0; j < grid[0].size(); j++)
            {
                if(!visited[i][j] && grid[i][j] == 1)
                {   
                    int area = dfs(pVisited, grid, i, j);
                    maxArea = area > maxArea? area : maxArea;
                    
                }
                visited[i][j] = true;
            }
        }
        return maxArea;
    }
};