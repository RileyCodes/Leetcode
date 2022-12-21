class NumMatrix {
public:

    vector<vector<int>> ps;
    NumMatrix(vector<vector<int>>& matrix) {
        for(int row = 0; row < matrix.size(); ++row)
        {
            ps.emplace_back(vector<int>());
            ps[row].emplace_back(matrix[row][0]);
            if(row > 0)
                ps[row][0] += ps[row - 1][0];

            for(int col = 1; col < matrix[0].size(); ++col)
            {
                auto res = ps[row][col - 1] + matrix[row][col];
                if(row > 0)
                {
                    res += ps[row - 1][col];
                    res -= ps[row - 1][col - 1];
                }
                    
                ps[row].emplace_back(res);
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        int num1 = col1 > 0 ? ps[row2][col1 - 1] : 0;
        int num2 = row1 > 0 ? ps[row1 - 1][col2] : 0;
        int num3 = (col1 > 0 && row1 > 0)? ps[row1 - 1][col1 - 1] : 0;
        return ps[row2][col2] - num1 - num2 + num3;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */