class Solution {
public:

    unordered_map<int, int> parents;

    int cityCnt = -1;
    int find(int a)
    {
        if(parents.count(a) == 0)
            parents[a] = a;
        if(a == parents[a])
            return a;
        parents[a] = find(parents[a]);
        return parents[a];
    }

    void _union(int a, int b)
    {
        int pA = find(a);
        int pB = find(b);
        if(pA == pB)
            return;
        parents[pA] = pB;
        --cityCnt;
    }

    int minimumCost(int n, vector<vector<int>>& connections) {
        cityCnt = n;
        for(int i = 1; i <=n; ++i)
            parents[i] = i;

        sort(connections.begin(),connections.end(),[](auto& a, auto&b )
        {
            return a[2] < b[2];
        });
        
        int ans = 0;
        
        for(int i = 0; i < connections.size(); ++i)
        {
            if(find(connections[i][0]) != find(connections[i][1]))
            {
                _union(find(connections[i][0]), find(connections[i][1]));
                ans += connections[i][2];
            }
        }

        return cityCnt == 1 ? ans : -1;
    }
};