class Solution {
public:

    int recur(vector<int>& nums, int begin, int end)
    {
        if(end - begin < 1)
            return 0;
        
        int mid = (begin + end) / 2;
        int lCnt = recur(nums, begin, mid);
        int rCnt = recur(nums, mid + 1, end);
        int thisCnt = 0;

        int lP = begin, rP = mid + 1;
        vector<int> tmp;

        int j = rP;
        while(lP <= mid || rP <= end)
        {
            
            if(lP <= mid && (rP > end || nums[lP] < nums[rP]))
            {
                while(j <= end && nums[lP] > (long long)nums[j] * 2 )
                {
                    ++j;
                }
                thisCnt = thisCnt + (j - mid - 1);
                tmp.emplace_back(nums[lP]);
                ++lP;
            }
            else
            {
                tmp.emplace_back(nums[rP]);
                ++rP;
            }
        }
            

        for(int i = begin ; i <= end ;++i)
            nums[i] = tmp[i - begin]; 


        return lCnt + rCnt + thisCnt;
    }

    int reversePairs(vector<int>& nums) {
        return recur(nums, 0 , nums.size() - 1);
    }
};