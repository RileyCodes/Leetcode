class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int minDiff = INT_MAX;
        for(int i = 1; i < arr.size(); ++i)
        {
            int diff = abs(arr[i] - arr[i - 1]);
            minDiff = min(minDiff, diff);
        }
        vector<vector<int>> ans;
        for(int i = 1; i < arr.size(); ++i)
        {
            if(abs(arr[i] - arr[i - 1]) == minDiff)
            {
                vector<int> pair;
                pair.emplace_back(arr[i - 1]);
                pair.emplace_back(arr[i]);
                ans.emplace_back(pair);
            }
        } 
        return ans;
    }
};