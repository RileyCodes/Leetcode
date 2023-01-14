class Solution {
public:

    set<int> visited;
    int cntV(int node, vector<vector<bool>>& mat)
    {
        if(visited.count(node))
            return 0;
        visited.insert(node);
        int res = 1;
        for(int i = 0; i < mat.size(); ++i)
        {
            if(mat[node][i])
                res += cntV(i, mat);
        }
        return res;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
    
        vector<vector<bool>> mat;
        mat.resize(n);
        for(int i = 0 ; i < n; ++i)
            mat[i].resize(n);

        for(auto&& edge : edges)
        {
            mat[edge[0]][edge[1]] = true;
            mat[edge[1]][edge[0]] = true;
        }

        int vCount = cntV(0, mat);

        return vCount == n && edges.size() == n - 1;
    }
};