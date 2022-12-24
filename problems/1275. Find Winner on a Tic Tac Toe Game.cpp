class Solution {
public:
    
    int dfs(int i,int j, int mark,vector<vector<int>>& grid,vector<vector<bool>>& visited,int start)
    {
        int cnt = 0;
        if(visited[i][j])
            return 0;
        
        if(grid[i][j] != mark)
            return 0;   
        else 
            ++cnt;
        
        visited[i][j] = true;
        
        const int dir_x[] = {0,0,1,-1,1,-1,-1,1};
        const int dir_y[] = {1,-1,0,0,1,-1,1,-1};
        
        for(int l = start; l < start + 2; ++l)
        {
            int cx = i + dir_x[l];
            int cy = j + dir_y[l];
            if(cx >= 0 && cx < 3 && cy >= 0 && cy <3)
                cnt += dfs(cx,cy,mark,grid,visited,start);                 
        }
  
        return cnt;
    }
    
    string tictactoe(vector<vector<int>>& moves) {
        bool isA = true;
        //0 - empty 1 - A 2 - B
        
        vector<vector<int>> grid(3,vector<int>(3));
        
        for(int i = 0 ; i < moves.size(); ++i)
        {
            
            int mark = isA? 1 : 2;
            
            grid[moves[i][0]][moves[i][1]] = mark;
            
            for(int k = 0; k < 8; k +=2)
            {
                vector<vector<bool>> visited(3,vector<bool>(3));
                if(dfs(moves[i][0],moves[i][1],mark,grid,visited,k) >= 3)
                {
                    return isA? "A" : "B";
                }                
            }
            
            if(i >= 8)
                return "Draw";
            
            isA = !isA;
        }
        return "Pending";
    }
};