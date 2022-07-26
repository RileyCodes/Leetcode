class Solution {
public:
    vector<vector<int>> combine(int n, int k) {        
        vector<vector<int>> result;
        vector<int> path(k);
        int depth = 0;
        path[0] = 1;
        while(depth >= 0)
        {       
            if(path[depth] <= n)
            {
                if(depth == k - 1)
                    result.emplace_back(path);      
                else
                {
                    ++depth;
                    path[depth] = path[depth - 1] + 1;
                    continue;                         
                }
            }
            else
                --depth;
            if(depth >= 0)
                ++path[depth];
        }
        return result;
    }
};