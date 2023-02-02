class Solution {
public:

    vector<int> parent;
    int find(int v)
    {
        if(v < 0)
            return v;
        if(v == parent[v])
            return v;
        parent[v] = find(parent[v]);

        return parent[v];
    }

    void _union(int a, int b)
    {
        int pA = find(a);
        int pB = find(b);
        if(pA == pB)
            return;
        parent[pA] = pB;
    }

    set<int> visited;
    bool dfs(vector<vector<int>>& graph, int v, int dummy)
    {
        
        const int dummy1 = -1, dummy2 = -2;
        if(visited.count(v))
        {
            int parent = find(v);
            if(parent != dummy)
                return false;
            return true;
        }

        visited.insert(v);
        _union(v, dummy);
        int nextDummy = dummy == dummy1? dummy2 : dummy1;
        int res = true;
        for(auto&& adj : graph[v])
            res = res && dfs(graph, adj , nextDummy);
        return res;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        parent.resize(graph.size());
        for(int i = 0; i < parent.size(); ++i)
            parent[i] = i;

        const int dummy1 = -1, dummy2 = -2;
        int res = true;
        for(int i = 0; i < graph.size(); ++i)
        {
            if(visited.count(i))
                continue;
            res = res && dfs(graph, i, dummy1);
        }


        return res;
    }
};