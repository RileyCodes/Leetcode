class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        ++rowIndex;
        vector<int> ans(rowIndex);
        
        for(int i = 0; i < rowIndex;++i)
        {
            for(int j = i ; j >= 0; --j)
            {
                if(j == 0 || j == i)
                    ans[j] = 1;
                else
                {
                    ans[j] = ans[j - 1] + ans[j];
                }
            }
        }
        
        return ans;
    }
};