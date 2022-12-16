class Solution {
public:

    vector<int> dp;

    int maxResult(vector<int>& nums, int k) {
        dp.resize(nums.size());

        dp[0] = nums[0];

        multiset<int,greater<int>> m;
        m.insert(dp[0]);

        for(int i = 1 ; i < nums.size(); ++i)
        {
            dp[i] = *m.begin();
            dp[i] += nums[i];
            
            if(i - k >= 0)
                m.erase(m.lower_bound(dp[max(i - k,0)]));

            m.insert(dp[i]);
        }
        return dp[nums.size() - 1];
    }
};;