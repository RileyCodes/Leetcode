class Solution {
public:

    unordered_map<int, bool> colored;
    unordered_map<int, vector<int>> graph;

    bool dfs(int v, bool color,bool any = false)
    {
        int res = true;
        if(colored.count(v) && colored[v] != color && !any)
        {
            return false;
        }
        else if(colored.count(v))
            return true;

        colored[v] = color;

        for(auto&& targetV : graph[v])
            res = res && dfs(targetV, !color);
            
        return res;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        for(int i = 0; i < dislikes.size(); ++i)
        {
            auto& lst = dislikes[i];
            if(graph.count(lst[0]) == 0)
                graph[lst[0]] = vector<int>();            
            graph[lst[0]].emplace_back(lst[1]);

            if(graph.count(lst[1]) == 0)
                graph[lst[1]] = vector<int>();            
            graph[lst[1]].emplace_back(lst[0]);            
        }

        int res = true;
        for(auto&& ele : graph)
            res = res && dfs(ele.first,true, true);

        return res;
    }
};