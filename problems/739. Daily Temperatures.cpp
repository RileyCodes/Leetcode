class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size());
        stack<int> s;
        s.push(temperatures.size() - 1);

        for(int i = temperatures.size() - 1; i >= 0; --i)
        {
            while(!s.empty() && temperatures[i] >= temperatures[s.top()])
                s.pop();

            if(!s.empty() && temperatures[i] < temperatures[s.top()])
                ans[i] = s.top() - i;
            s.push(i);
        }
        return ans;
    }
};