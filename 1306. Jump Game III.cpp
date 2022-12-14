class Solution {
public:
    set<int> visited;
    bool canReach(vector<int>& arr, int start) {
        if(arr[start] == 0)
            return true;
        if(visited.count(start) > 0)
            return false;
        visited.insert(start);
        
        if(start + arr[start] < arr.size())
        {
            if(canReach(arr, start + arr[start]))
                return true;
        }
        if(start - arr[start] >= 0)
        {
            if(canReach(arr, start - arr[start]))
                return true;
        }
        
        return false;
    }
};