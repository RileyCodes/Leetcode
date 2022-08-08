class Solution {
public:
    /*
    这道题要求我们找出所有抵达目标的路径组合。
    数据是无环有向图，因此我们并不需要担心走回头路这种情况。
    每次递归的时候，至少都有一个选择是不一样的，因此我们只需要递归出所有抵达最大数的组合就行了。
    
    可以想象到潜在的问题是断头路，或者说指向到不是 最大顶点的路径。
    因此，我们需判定找到了全局最大的顶点才添加路径组合。
    
    因为Constraints:
    n == graph.length
    而我们要找到的是指向 n - 1的路径，所以目标顶点就是graph.size() - 1
    */
    
    void dfs(vector<vector<int>>& graph,int targetId, vector<vector<int>>& result, int vertexId,vector<int> path)
    {
        path.emplace_back(vertexId);
        if(vertexId == targetId)
        {
            result.emplace_back(path);
            return;
        }
        for(int i = 0;i < graph[vertexId].size(); ++i)
        {
            dfs(graph,targetId,result,graph[vertexId][i],path);
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        dfs(graph, graph.size() - 1, result, 0, vector<int>());
        return result;
    }
};