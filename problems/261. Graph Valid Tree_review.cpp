class Solution {
public:

    set<int> visited;

    int dfs(vector<vector<int>>& adj, int v)
    {
        if(visited.count(v))
            return -1;

        visited.insert(v);

        int cnt = 0;
        for(int i = 0; i < adj[v].size(); ++i)
            cnt = cnt + 1 + dfs(adj, adj[v][i]);

        return cnt;
    }


    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        int edgeCnt = 0;
        for(auto&& edge : edges)
        {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
            ++edgeCnt;
        }

        if(edgeCnt != n -1)
            return false;

        int res = dfs(adj, 0);
        cout << res;
        return res == n - 1;
    }
};