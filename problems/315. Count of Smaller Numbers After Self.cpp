class Solution {
public:

    vector<int> count;

    void recur(vector<pair<int,int>>& nums, int begin, int end)
    {
        if(begin >= end)
            return;
        vector<pair<int,int>> tmp(end - begin + 1);
        int mid = (begin + end) / 2;
        recur(nums, begin, mid);
        recur(nums, mid + 1, end);

        int lP = begin, rP = mid + 1;
        int i = 0;
        while(lP <= mid || rP <= end)
        {
            if(lP <= mid && (rP > end || nums[lP].first <= nums[rP].first))
            {
                tmp[i] = nums[lP];
                
                count[nums[lP].second] += rP - (mid + 1);
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

    vector<int> countSmaller(vector<int>& nums) {
        count.resize(nums.size());
        vector<pair<int, int>> pairedNums;
        for(int i = 0; i < nums.size(); ++i)
            pairedNums.emplace_back(pair<int,int>(nums[i], i));        

        recur(pairedNums, 0, nums.size() - 1);
        return count;
    }
};