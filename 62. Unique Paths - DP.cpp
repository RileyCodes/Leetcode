class Solution {
public:
    /*
    动态规划思路：
    
    最后一步 - 考虑这道题最后一步必然是从左边走过来的，或者是从上边走过来的
    
    子问题 - 如果是从左边走过来的，那么当我们考虑左边哪一格的时候，对于怎么到左边那一格，我们的行动空间的宽度旧减少了1
    而对于上面那一格，我们的行动空间的高度少了1
    
    状态转移方程 - f(m,n) = f(m - 1,n) + f(m,n - 1)
    边界条件f(1,1) = 1
    
    */
    int uniquePaths(int m, int n) {
        
        int arr[m][n];
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(i == 0 || j == 0)
                    arr[i][j] = 1;
                else
                {
                    int a = arr[i - 1][j];
                    int b = arr[i][j - 1];
                    arr[i][j] =  a + b;   
                }
            }
        }
        return arr[m - 1][n - 1];
    }
};