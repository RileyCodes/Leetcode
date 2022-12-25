class Solution {
public:

    unordered_map<unsigned long long,int> s;

    int recur(vector<int>& prefix_sum, vector<int>& nums, int start, int end, int k)
    {
        unsigned long long hash = 0;
        hash |= start; hash <<= 32; hash |= k;

        if(s.count(hash))
            return s[hash];

        int prefixToIgnore = prefix_sum[start];
        if(k == 1)
        {
            auto res = prefix_sum[end - k + 1] - prefixToIgnore;
            s[hash] = res;
            return res;
        }
        int minRes = INT_MAX;
        for(int i = start + 1; i <= (end - k) + 1; ++i)
        {
            int rangeSum = prefix_sum[i] - prefixToIgnore;
            auto res = recur(prefix_sum, nums, i, end, k - 1);
            minRes = min(minRes, max(rangeSum,min(minRes, res)));
        }
        s[hash] = minRes;
        return minRes;
    }

    int splitArray(vector<int>& nums, int k) {
        vector<int> prefix_sum(nums.size() + 1);
        for(int i = 0; i < nums.size(); ++i)
        {   
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];
        }

        auto res = recur(prefix_sum, nums, 0, nums.size(), k);

        return res;    
    }
};