class Solution {
public:

    int count = 0;

    void recur(vector<int>& nums, int begin, int end)
    {
        if(begin >= end)
            return;
        vector<int> tmp(end - begin + 1);
        int mid = (begin + end) / 2;
        recur(nums, begin, mid);
        recur(nums, mid + 1, end);

        int right = mid + 1;
        for(int i = begin;i <= mid; ++i)
        {
            while(right <= end && nums[i] > (long long)nums[right] * (long long)2)
                ++right;
            count += right - (mid + 1);
        }

        int lP = begin, rP = mid + 1;
        int i = 0;
        while(lP <= mid || rP <= end)
        {
            if(lP <= mid && (rP > end || nums[lP] <= nums[rP]))
            {
                tmp[i] = nums[lP];
                ++lP;
            }
            else
            {
                tmp[i] = nums[rP];
                ++rP;
            }
            ++i;
        }
        i = begin;
        for(auto&& num : tmp)
            nums[i++] = num;        
    }

    int reversePairs(vector<int>& nums) {      

        recur(nums, 0, nums.size() - 1);
        return count;
    }
};