class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int, vector<pair<int, double>>> adj;

        auto compare = [](pair<int, double>&a, pair<int, double>&b)
        {
            return a.second < b.second;
        };

        priority_queue<pair<int, double>, vector<pair<int, double>>, decltype(compare)> q(compare);

        for(int i = 0; i < edges.size(); ++i)
        {
            auto& edge = edges[i];
            adj[edge[0]].emplace_back(pair<int, double>(edge[1], succProb[i]));
            adj[edge[1]].emplace_back(pair<int, double>(edge[0], succProb[i]));
        }
        
        q.push(pair<int, double>(start, 1.0f));

        unordered_map<int, double> distTo;
        for(auto&& kv : adj)
        {
            if(kv.first == start)
                distTo[kv.first] = 1.0f;
            else
                distTo[kv.first] = 0.0f;
        }

        while(!q.empty())
        {
            auto p = q.top();

            if(p.first == end)
                return p.second;

            q.pop();

            if(p.second < distTo[p.first])
                continue;
            for(auto&& adjV : adj[p.first])
            {
                double distToNextNode = distTo[p.first] * adjV.second;
                if (distTo[adjV.first] < distToNextNode) {
                    distTo[adjV.first] = distToNextNode;
                    q.push(pair<int, double>(adjV.first, distToNextNode));
                }                
            }
        }
        return distTo[end];
    }
};