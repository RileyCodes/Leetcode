class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {        
        vector<pair<int,int>> rotOranges;
        int timeCounter = 0;
        int freshOrangeCounter = 0;
        queue<pair<int,int>> bfs_queue;
        bool visited[grid.size()][grid[0].size()];
        
        
        for(int i = 0; i < grid.size();i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                visited[i][j] = false;//初始化
                if(grid[i][j] == 2)
                {
                    auto point = pair<int,int>(i,j);
                    rotOranges.emplace_back(point);
                    bfs_queue.push(point);
                    visited[i][j] = true;
                }
                else if(grid[i][j] == 1)
                    ++freshOrangeCounter;
            }
        }
        bfs_queue.push(pair<int,int>(-1,-1));//标记一轮结束

        if(freshOrangeCounter == 0)
            return 0;        
        if(rotOranges.size() == 0)
            return -1;


        const int x_direction[4] = {1,-1,0,0};
        const int y_direction[4] = {0,0,1,-1};
        
        bool isLastWhileMark = false;
        while(1)
        {
            auto point = bfs_queue.front();
            bfs_queue.pop();
            if(point.first == -1)
            {
                if(isLastWhileMark)
                    return -1;
                bfs_queue.push(point);
                timeCounter++;
                isLastWhileMark = true;
                continue;
            }
            else
                isLastWhileMark = false;
            
            auto nextPoint = pair<int,int>();
            for(int i=0; i < 4; i++)
            {
                nextPoint.first = point.first + x_direction[i];
                nextPoint.second = point.second + y_direction[i];
                if(nextPoint.first < 0 || nextPoint.first >= grid.size() ||
                  nextPoint.second < 0 || nextPoint.second >= grid[0].size() ||
                   visited[nextPoint.first][nextPoint.second] ||
                   grid[nextPoint.first][nextPoint.second] == 0
                  )
                    continue;
                
                visited[nextPoint.first][nextPoint.second] = true;
                
                if(grid[nextPoint.first][nextPoint.second] == 1)
                    --freshOrangeCounter;
                
                if(freshOrangeCounter == 0)
                    return timeCounter + 1;        
                bfs_queue.push(nextPoint);
            }
        }
        return -1;
    }
};