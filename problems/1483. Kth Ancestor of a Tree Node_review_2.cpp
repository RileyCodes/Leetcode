class TreeAncestor {
public:
    vector<vector<int>> v;
    TreeAncestor(int n, vector<int>& parent) {
        for(int i = 0; i < n; ++i)
        {
            v.emplace_back(vector<int>());
            v[i].emplace_back(parent[i]);
        }
        for(int i = 1; i < 18; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(v[j][i - 1] != -1)
                    v[j].emplace_back(v[v[j][i - 1]][i - 1]);
                else
                    v[j].emplace_back(-1);
            }
        }

        
    }
    
    int getKthAncestor(int node, int k) {
        if(node == -1)
            return -1;
        int maxPower = 1;
        int power = 0;
        while(maxPower * 2 < k)
        {
            maxPower *= 2;
            ++power;
        }
        if(maxPower == k)
            return v[node][power];
        
        return getKthAncestor(v[node][power], k - maxPower);
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */