class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj;
        adj.resize(n + 1);
        for(auto&& time : times)
            adj[time[0]].emplace_back(pair(time[1],time[2]));

        auto compare = [](auto& a, auto& b)
        {
            return a.second > b.second;
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>,decltype(compare)> q(compare);

        vector<int> distTo(n + 1, INT_MAX);
        distTo[k] = 0;

        q.push(pair(k, 0));

        while(!q.empty())
        {
            auto top = q.top();
            if(distTo[top.first] < top.second)
            {
                q.pop();
                continue;
            }

            for(auto&& adjV : adj[top.first])
            {
                auto newDist = top.second + adjV.second;
                if(newDist < distTo[adjV.first])
                {
                    distTo[adjV.first] = newDist;
                    q.push(pair(adjV.first, newDist));
                }
            }
            
            q.pop();
        }
        
        distTo[0] = INT_MIN;
        int _max = distTo[0];
        
        for(auto&& dist : distTo)
            _max = max(_max, dist);

        return _max == INT_MAX? -1 : _max;
    }
};