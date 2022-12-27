class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int lP = 0, rP = 0;
        deque<int> q;
        while(rP - lP < k)
        {
            while(!q.empty() && nums[rP] > q.front())
                q.pop_front();
            q.push_front(nums[rP]);
            ++rP;
        }

        vector<int> ans;
        ans.emplace_back(q.back());
        if(nums[lP] == q.back())
            q.pop_back();
        ++lP;

        while(rP < nums.size())
        {
            while(!q.empty() && nums[rP] > q.front())
                q.pop_front();
            q.push_front(nums[rP]);
            ++rP;
            ans.emplace_back(q.back());
            if(nums[lP] == q.back())
                q.pop_back();
            ++lP;                        
        }


        return ans;
    }
};