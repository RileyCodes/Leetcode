class Solution {
public:

    //[a,b]
    long long getRangeSum(vector<long long>& prefix, int a, int b)
    {
        //[a,b] = [0, b] - [0, a - 1]
        return prefix[b + 1] - prefix[a];
    }


    int recur(vector<long long>& prefix, int begin, int end, int lower, int upper)
    {
        if(end - begin < 1)
            return 0;
        
        int mid = (begin + end) / 2;
        int lCnt = recur(prefix, begin, mid, lower, upper);
        int rCnt = recur(prefix, mid + 1, end, lower, upper);

        vector<long long> tmp;
        int lP = begin, rP = mid + 1;
        int localCnt = 0;

        int leftBound = mid + 1;
        int rightBound = mid + 1;
        for(int i = begin; i < mid + 1; ++i)
        {
            while(leftBound  <= end && prefix[leftBound] - prefix[i] < lower)
                ++leftBound;
            while(rightBound <= end && prefix[rightBound] - prefix[i] <= upper)
                ++rightBound;
            localCnt += rightBound - leftBound;
        }

        while(lP <= mid || rP <= end)
        {
            if(lP <= mid && (rP > end || prefix[lP] < prefix[rP]))
            {
                tmp.emplace_back(prefix[lP]);
                lP++;
            }
            else
            {
                tmp.emplace_back(prefix[rP]);
                rP++;
            }
        }

        for(int i = begin; i <= end; ++i)
            prefix[i] = tmp[i - begin];

        return lCnt + rCnt + localCnt;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {

        //[a, b)
        vector<long long> prefix(nums.size() + 1);

        for(int i = 0; i < nums.size(); ++i)
            prefix[i + 1] = prefix[i] +  nums[i];

        return recur(prefix, 0, prefix.size() - 1 , lower, upper);
    }
};