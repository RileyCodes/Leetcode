class Solution {
public:

    vector<int> parent;

    int find(int v)
    {
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


    int minimumCost(int n, vector<vector<int>>& connections) {

        parent.resize(n + 1);
        int componentCnt = n;
        for(int i = 0 ; i <= n ; ++i)
            parent[i] = i;

        auto compare = [](vector<int>& arr1, vector<int>& arr2)
        {return arr1[2] > arr2[2]; };


        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> q(compare);

        for(auto&& connection : connections)
            q.push(connection);

        int ans = 0;
        while(!q.empty())
        {
            int pA = find(q.top()[0]);
            int pB = find(q.top()[1]);
            if(pA != pB)
            {
                --componentCnt;
                _union(q.top()[0], q.top()[1]);
                ans += q.top()[2];
            }
            q.pop();
        }
        if(componentCnt != 1)
            return -1;
        return ans;
    }
};
