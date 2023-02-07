class Solution {
public:
    typedef pair<pair<int, int>, int> Entry;
    typedef pair<int, int> Point;

    vector<Point> getAdj(int x, int y, vector<vector<int>>& heights)
    {
        vector<Point> res;
        if(x > 0)
            res.emplace_back(x - 1, y);
        if(x < heights[0].size() - 1)
            res.emplace_back(x + 1, y);
        if(y > 0)
            res.emplace_back(x, y - 1);
        if(y < heights.size() - 1)
            res.emplace_back(x,y + 1);

        //cout << x << ":" << y << " -- " << res.size() << endl;
        return res;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> distTo(heights.size(), vector<int>(heights[0].size(),INT_MAX));
        distTo[0][0] = 0;

        auto compare = [](auto&a, auto& b){return a.second > b.second;};
        priority_queue<Entry,vector<Entry>, decltype(compare)> q(compare);
        
        Entry e({0,0}, 0);
        q.push(e);
        int minFound = INT_MAX;
        while(!q.empty())
        {
            Entry e = q.top();
            if(e.second > distTo[e.first.second][e.first.first])
            {
                q.pop();
                continue;
            }

            for(auto&& adjV : getAdj(e.first.first, e.first.second, heights))
            {
                int newDist = max(e.second,
                    abs(heights[e.first.second][e.first.first] - heights[adjV.second][adjV.first]));
                    
                if(newDist < distTo[adjV.second][adjV.first])
                {
                    distTo[adjV.second][adjV.first] = newDist;
                    q.push(Entry(adjV, newDist));
                }
            }
            q.pop();
        }

        return distTo.back().back();
    }
};