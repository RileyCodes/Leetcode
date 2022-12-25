class Solution {
public:

    int maxFound = INT_MAX;
    set<unsigned long long> s;

    void recur(vector<int>& prefix_sum, vector<int>& nums, int start, int end, int k, int max_sum = 0)
    {
        unsigned long long hash = 0;
        hash += start;
        hash += (hash << 10);
        hash ^= (hash >> 6);
        hash += k;
        hash += (hash << 10);
        hash ^= (hash >> 6);
        hash += max_sum;
        hash += (hash << 10);
        hash ^= (hash >> 6);          



        if(s.count(hash))
            return;

        int prefixToIgnore = prefix_sum[start];
        if(k == 1)
        {
            maxFound = min(max(max_sum, prefix_sum[end - k + 1] - prefixToIgnore), maxFound);
            s.insert(hash);
            return;
        }

        for(int i = start + 1; i <= (end - k) + 1; ++i)
        {
            int rangeSum = prefix_sum[i] - prefixToIgnore;
            recur(prefix_sum, nums, i, end, k - 1, max(max_sum, rangeSum));
        }
        s.insert(hash);
        return;
    }

    int splitArray(vector<int>& nums, int k) {
        vector<int> prefix_sum(nums.size() + 1);
        for(int i = 0; i < nums.size(); ++i)
        {   
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];
        }

        recur(prefix_sum, nums, 0, nums.size(), k);

        return maxFound;    
    }
};