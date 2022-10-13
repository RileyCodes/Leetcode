class TreeAncestor {
public:

    vector<vector<int>> d;
    
    
    TreeAncestor(int n, vector<int>& parent) {
        d.emplace_back(parent);
        
        for(int i = 1; i < 20; ++i)
        {
            d.emplace_back(vector<int>(n));
            for(int j = 0; j < n; ++j)
            {
                int parentIndex = d[i- 1][j];
                int parent = (parentIndex == -1)? -1 :  d[i - 1][parentIndex];
                d[i][j] = parent;
            }
        }
        
        for(auto row : d)
        {
            for(auto col : row)
            {
                cout << col << " ";
            }
            cout << endl;
        }
        
        
    }

    int getKthAncestor(int node, int k) {
        int parent = node;
        for(int i = 0; i < 20; ++i)
        {
            if(k & (1 << i))
            {
                parent = d[i][parent];
                if(parent == -1)
                    return -1;
            }
        }
        
        return parent;
    }
};