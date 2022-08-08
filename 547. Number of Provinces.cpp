class Solution {
public:
    /*
    这道题的数据结构是
    [第几个顶点][和第几个顶点是否联通]  1 = 联通 0 = 不联通
    例：[0][1] == 1 意味着第一个顶点和第二个顶点联通。
    
    使用DFS搜索，每个顶点对着所有联通的方向分裂出N个DFS调用搜索，并且标记其已经被访问过了。
    */
    
    void dfs(vector<vector<int>>& isConnected, vector<int>& visited,int vertexId)
    {
        if(visited[vertexId])//不访问已经访问过的。
            return;
        
        visited[vertexId] = true;
        
        //分裂出访问所有联通的近邻顶点的dfs
        for(int i =0; i < isConnected[0].size(); ++i)
        {
            if(i == vertexId)
                continue;//不访问自身
            if(!isConnected[vertexId][i])//仅访问联通的
                continue;
            
            dfs(isConnected,visited,i);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        vector<int> visited(isConnected.size());
        int count = 0;
        for(int i = 0; i < isConnected.size(); ++i)
        {
            if(visited[i])
                continue;
            ++count;
            dfs(isConnected,visited,i);
        }
        
        return count;
    }
};