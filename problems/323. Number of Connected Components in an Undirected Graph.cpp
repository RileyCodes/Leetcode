class Solution {
public:
    vector<int> parent;
    int count = 0;

    void u(int a, int b)
    {
        int parentA = find(a);
        int parentB = find(b);

        if(parentA == parentB)
            return;
        parent[parentA] = parent[parentB];
        --count;
    }

    int find(int v)
    {
        if(v == parent[v])
            return v;
        parent[v] = find(parent[v]);
        return parent[v];
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        count = n;
        for(int i = 0;i < n; ++i)
            parent[i] = i;

        for(auto&& edge : edges)
            u(edge[0],edge[1]);
        return count;
    }
};