class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        for(int i=0; i < mat.size(); i++)
        {
            for(int j=0; j < mat[0].size(); j++)
            {
                if(mat[i][j] != 0)
                    mat[i][j] = INT_MAX - 100000;
                if(j > 0 && mat[i][j] != 0)
                    mat[i][j] = mat[i][j - 1] + 1;
                if(i > 0 && mat[i][j] != 0)
                  mat[i][j] = min(mat[i][j],mat[i - 1][j] + 1);
            }
        }
    
        for(int i = mat.size() - 1; i >=0; i--)
        {
            for(int j = mat[0].size() - 1; j >=0 ;j--)
            {
                if(j < mat[0].size() - 1 && mat[i][j] != 0)
                    mat[i][j] = min(mat[i][j],mat[i][j + 1] + 1);
                
                if(i < mat.size() - 1 && mat[i][j] != 0)
                    mat[i][j] = min(mat[i][j],mat[i + 1][j] + 1);
            }
        }
        return mat;
    }
};