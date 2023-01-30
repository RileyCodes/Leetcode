class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        int popCnt = 0;
        for(int i = 0; i < k ; ++i)
        {
            while(!q.empty() && q.front() < nums[i])
                q.pop_front();
            q.push_front(nums[i]);
        }
        ans.emplace_back(q.back());
        int lP = 1, rP = k;

        while(rP < nums.size())
        {
            if(nums[lP - 1] == q.back())
                q.pop_back();

            while(!q.empty() && q.front() < nums[rP])
                q.pop_front();
            q.push_front(nums[rP]);
            ++lP;
            ++rP;
            ans.emplace_back(q.back());
        }
        return ans;
    }
};