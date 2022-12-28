class TreeAncestor {
public:

    vector<vector<int>> v;
    const int maxCol = 16;
    TreeAncestor(int n, vector<int>& parent) {        
        for(int i = 0; i < maxCol; ++i)
        {
            for(int cur_row = 0; cur_row < parent.size(); ++cur_row)
            {
                if(i == 0)
                {
                    v.emplace_back(vector<int>(maxCol));
                    v[cur_row][i] = parent[cur_row];
                    continue;
                }
                if(v[cur_row][i - 1] == -1)
                    v[cur_row][i] = -1;
                else
                    v[cur_row][i] = v[v[cur_row][i - 1]][i - 1];
            }
        }        
    }
    
    int getKthAncestor(int node, int k) {
        //cout << "Debug info: node = " << node << ", k = " << k << endl;

        if(node == -1)
            return -1;

        

        int num = 1;
        int i = 0;
        while((num << 1) < k)
        {
            ++i;
            num <<= 1;
        }
        //cout << "Debug info: num = " << num << ", i = " << i << endl;

        if(num == k)
            return v[node][i];
        return getKthAncestor(v[node][i], k - num);
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */