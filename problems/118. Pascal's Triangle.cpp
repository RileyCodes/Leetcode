class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans(numRows);
        
        for(int i = 0; i <numRows; ++i)
        {
            ans[i] = vector<int>(i + 1);
            for(int j = 0; j < i + 1;++j)
            {
                ans[i][j] = 1;
            }
        }
        
        for(int i = 1; i <numRows - 1; ++i)
        {
            for(int j = 0; j < ans[i].size() - 1; ++j)
            {
                ans[i + 1][j + 1] = ans[i][j] + ans[i][j + 1];
            }
        }
        
        
        return ans;
    }
};