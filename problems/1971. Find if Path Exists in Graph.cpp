class Solution {
public:

    vector<int> parents;

    int find(int v)
    {
        if(parents[v] == v)
            return v;
        parents[v] = find(parents[v]);
        return parents[v];
    }

    void _union(int p, int q)
    {
        int pP = find(p);
        int pQ = find(q);
        if(pP == pQ)
            return;
        parents[pP] = parents[pQ];
    }


    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        parents.resize(n);
        for(int i = 0; i < n; ++i)
            parents[i] = i;

        for(auto&& edge : edges)
            _union(edge[0], edge[1]);

        return find(parents[source]) == find(parents[destination]);
    }
};