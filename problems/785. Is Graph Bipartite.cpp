class Solution {
public:

    unordered_map<int, bool> visited;

    bool dfs(int nodeId, vector<vector<int>>& graph, bool color)
    {
        if(visited.count(nodeId))
        {
            if(visited[nodeId] != color)
                return false;
            return true;
        }
        visited[nodeId] = color;
        for(auto&& targetId : graph[nodeId])
        {
            if(!dfs(targetId, graph, !color))
                return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int res = true;
        for(int i = 0; i < graph.size(); ++i)
        {
            if(!visited.count(i))
                res = res && dfs(i, graph, false);
        }
            
        return res;
    }
};
