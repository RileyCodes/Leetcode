class Solution {
public:

    vector<int> parents;

    int distance(const vector<int>& p1, const vector<int>& p2)
    {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }

    int find(int v)
    {
        if(v == parents[v])
            return v;
        parents[v] = find(parents[v]);
        return parents[v];
    }

    void _union(int a, int b)
    {
        int pA = find(a);
        int pB = find(b);
        if(pA == pB)
            return;
        parents[pA] = pB;
    }

    struct Data
    {
        int i,j,dis;
    };
    int minCostConnectPoints(vector<vector<int>>& points) {
        auto compare = [](Data& a, Data& b){ return a.dis > b.dis;};

        priority_queue<Data, vector<Data>, decltype(compare)> q(compare);
        for(int i = 0; i < points.size(); ++i)
        {
            for(int j = 0; j < points.size(); ++j)
            {
                if(i == j)
                    continue;
                Data d;
                d.i = i;
                d.j = j;
                d.dis = distance(points[i],points[j]);
                q.push(d);
            }
        }

        parents.resize(q.size());
        for(int i = 0; i < parents.size(); ++i)
            parents[i] = i;

        int ans = 0;
        while(!q.empty())
        {
            auto& top = q.top();
            if(find(top.i) != find(top.j))
            {
                _union(top.i,top.j);
                ans += top.dis;
            }
            q.pop();
        }


        return ans;
    }
};