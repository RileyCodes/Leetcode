class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        if(r * c != mat[0].size() * mat.size())
            return mat;
        
        vector<vector<int>> ans(r,vector<int>(c));
        
        int ans_col = 0;
        int ans_row = 0;
        
        for(int i = 0; i < mat.size(); ++i)
        {
            for(int j = 0; j < mat[0].size(); ++j)
            {
                ans[ans_row][ans_col] = mat[i][j];
                ++ans_col;
                if(ans_col >= c)
                {
                    ans_col = 0;
                    ++ans_row;
                }
            }
        }
        return ans;
    }
};