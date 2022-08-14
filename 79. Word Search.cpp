class Solution {
public:
    
    bool dfs(vector<vector<char>>& board, const string& word, int x, int y,int index)
    {
        if(word[index] != board[x][y])
            return false;
        
        board[x][y] = '*';
        
        if(word.size() - 1 == index)
            return true;
        
        static const int dir_x[4] = {0,0,1,-1};
        static const int dir_y[4] = {1,-1,0,0};
        
        for(int i = 0; i < 4; ++i)
        {
            int new_x = x + dir_x[i];
            int new_y = y + dir_y[i];
            if(new_x < 0 || new_x >= board.size() ||
              new_y < 0 || new_y >= board[0].size())
                continue;
            if(dfs(board,word,new_x,new_y, index + 1))
                return true;
        }
        
        board[x][y] = word[index];
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        //先遍历全局，遇到首字母就开一个DFS进程去看是否有完全匹配的路径
        
        if(board.size() * board[0].size() < word.size())
            return false;
        
        int frequency[128] = {};
        for(const auto &row : board) 
        {
            for(char chr : row) 
            {
                ++frequency[chr];
            }
        }
        for(char chr : word) 
        {
            if(--frequency[chr] < 0) 
                return false;
        } 
        
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j <board[0].size(); ++j)
            {
                if(dfs(board,word,i,j,0))
                    return true;
            }
        }
        return false;
    }
};