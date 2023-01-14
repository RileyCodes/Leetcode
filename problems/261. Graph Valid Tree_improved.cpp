class Solution {
public:

    set<int> visited;
    int cntV(int node, vector<vector<int>>& adj)
    {
        if(visited.count(node))
            return 0;
        visited.insert(node);
        int res = 1;
        for(int i = 0; i < adj[node].size(); ++i)
            res += cntV(adj[node][i], adj);
        return res;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
    
        if(edges.size() != n - 1)
            return false;
            
        vector<vector<int>> adj(n);
        for(auto&& edge: edges)
        {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }

        return cntV(0, adj) == n;
    }
};