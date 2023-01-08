class Solution {
public:
    unordered_map<int, vector<int>> m;

    vector<int> postOrder;
    set<int> processed;

    bool recur(int i, set<int>& visited)
    {
        if(visited.count(i))
            return false;

        if(processed.count(i))
            return true;

        if(m.count(i) == 0)
        {
            processed.insert(i);
            postOrder.emplace_back(i);
            return true;
        }
        visited.insert(i);
        bool res = true;
        for(int j = 0; j < m[i].size(); ++j)
        {
            res = res && recur(m[i][j], visited);
        }
        processed.insert(i);
        postOrder.emplace_back(i);
        visited.erase(i);
        return res;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        for(auto&& prereq : prerequisites)
        {
            if(m.count(prereq[0]) == 0)
                m[prereq[0]] = vector<int>();
            m[prereq[0]].emplace_back(prereq[1]);
        }
        int res = true;
        set<int> visited;
        for(int i = 0; i < numCourses; ++i)
            res = res && recur(i, visited);

        if(!res)
            return vector<int>();
        //reverse(postOrder.begin(),postOrder.end());
        return postOrder;
    }
};