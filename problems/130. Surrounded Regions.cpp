class Solution {
public:
    
    /*
    这道题要求把所有被X包括的O都反转为O。
    很容易发现，如果某个O的连通区域没有在地图边界，那么其自然就被X包裹。
    所以我们先把地图边界跑一圈，把没有被包裹的O都标记出来，然后再把剩下没被标记的全部写成X就行了。
    */
    
    void mark_region(vector<vector<char>>& board, vector<vector<bool>>& visited,int x, int y)
    {
        //把本区域全部访问一遍，标记为已读。
        if(board[x][y] == 'X')
            return;
        
        visited[x][y] = true;
        
        const int dir_x[4]{0,0,1,-1} ,dir_y[4]{1,-1,0,0};
        for(int i = 0;i < 4; ++i)
        {
            int new_x = x + dir_x[i];
            int new_y = y + dir_y[i];
            if(new_x < 0 || new_x >= board.size() 
               || new_y < 0 || new_y >= board[0].size() || visited[new_x][new_y])
                continue;
            
            mark_region(board,visited,new_x,new_y);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        
        
        vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size()));
        for(int i =0; i < board.size(); i++)//处理最左边竖着一排和最右边竖着一排
        {
            mark_region(board,visited,i,0);
            mark_region(board,visited,i,board[0].size() - 1);
        }
        for(int i =0; i < board[0].size(); i++)//处理最上面横着一排和最下面横着一排
        {
            mark_region(board,visited,0,i);
            mark_region(board,visited,board.size() - 1,i);
        }
        
        //全部标记完了，遍历内部(最外面一圈可以无视)
        for(int i = 1 ; i < board.size() - 1; ++i)
        {
            for(int j = 1; j < board[0].size(); ++j)
            {
                if(visited[i][j])
                    continue;
                board[i][j] = 'X';
            }
        }
        
        return;
    }
};