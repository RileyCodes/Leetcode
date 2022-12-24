class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> rowCount(mat.size());
        
        for(int i = 0; i < mat.size(); ++i)
        {
            for(int j = 0; j < mat[i].size();++j)
            {
                if(mat[i][j] == 1)
                    ++rowCount[i].first;
            }
            rowCount[i].second = i;
        }
        
        sort(rowCount.begin(),rowCount.end(),[&](const auto& v1,const auto& v2){
            if(v1 == v2)
                return v1.second < v2.second;
            return v1 < v2;
        });
        
        vector<int> ans(k);
        for(int i = 0; i < k; ++i)
        {
            ans[i] = rowCount[i].second;
        }
        
        return ans;
    }
};