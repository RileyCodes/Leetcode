class Solution {
public:

    unordered_map<int,bool> canFinishMap;

    bool canFinish(int i, unordered_map<int,vector<int>>& m,set<int>& visited)
    {
        if(!m.count(i))
            return true;
        if(visited.count(i))
            return false;
        visited.insert(i);

        bool res = true;
        for(auto&& prereqIndex : m[i])
        {
            if(canFinishMap.count(prereqIndex))
                res = res && canFinishMap[prereqIndex];
            else
                res = res && canFinish(prereqIndex,m,visited);
            if(!res)
                break;
        }
        visited.erase(i);
        canFinishMap[i] = res;
        return res;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> prereq_map;

        for(auto&& prereq : prerequisites)
        {
            if(prereq_map.count(prereq[0]) == 0)
                prereq_map[prereq[0]] = vector<int>();
            prereq_map[prereq[0]].emplace_back(prereq[1]);
        }

        bool ans = true;
        set<int> visited;
        for(int i = 0; i < numCourses;++i)
            ans = ans && canFinish(i, prereq_map, visited);
        return ans;
    }
};