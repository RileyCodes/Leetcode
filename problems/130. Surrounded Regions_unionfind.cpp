class Solution {
public:

    vector<int> parents;

    int find(int v)
    {
        if(v == parents[v])
            return v;
        parents[v] = find(parents[v]);
        return parents[v];
    }

    void _union(int a, int b)
    {
        int pA = find(a);
        int pB = find(b);
        if(pA == pB)
            return;
        parents[pA] = parents[pB];
    }

    int rowcolToIndex(int width, int row, int col)
    {
        return (width * row) + col;
    }

    void solve(vector<vector<char>>& board) {
        parents.resize((board.size() * board[0]. size()) + 1);  
        for(int i = 0; i < parents.size();++i)
            parents[i] = i;
        const int width = board[0].size();
        for(int i = 0; i < board.size(); ++i)
        {
            if(board[i][0] == 'O')
                _union(parents[rowcolToIndex(width, i , 0)], parents[parents.size() - 1]);
            if(board[i][width - 1] == 'O')
                _union(parents[rowcolToIndex(width,i  , width - 1)], parents[parents.size() - 1]);
        }

        for(int i = 0; i < width; ++i)
        {
            if(board[0][i] == 'O')
                _union(parents[rowcolToIndex(width, 0 , i)], parents[parents.size() - 1]);
            if(board[board.size() - 1][i] == 'O')
                _union(parents[rowcolToIndex(width, board.size() - 1 , i)], parents[parents.size() - 1]);                
        }

        int dir_x[]{0,0,-1,1};
        int dir_y[]{1,-1,0,0};
        for(int i = 0; i < board.size();++i)
        {
            for(int j = 0; j < board[0].size();++j)
            {
                if(board[i][j] == 'O')
                {
                    for(int k = 0; k < 4; ++k)
                    {
                        int nRow = i + dir_x[k];
                        int nCol = j + dir_y[k];
                        if(nRow >= 0 && nCol >= 0 && nRow < board.size() && nCol < board[0].size())
                        {
                            if(board[nRow][nCol] == 'O')
                            {
                                cout << "union" << endl;
                                _union(parents[rowcolToIndex(width, i,j)], parents[rowcolToIndex(width, nRow, nCol)]);
                            }
                                
                        }
                    }
                }
            }
        }

        for(int i = 0; i < board.size();++i)
        {
            for(int j = 0; j < board[0].size();++j)
            {
                if(find(parents[rowcolToIndex(width, i,j)]) != find(parents[parents.size() - 1]))
                    board[i][j] = 'X';
            }
        }        
    }
};