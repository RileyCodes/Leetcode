class Solution {
public:

    void recur(vector<int>& nums, int begin, int end) 
    {
        //if left bound is at or over right bound, return
        if(begin >= end)
            return;

        int mid = (begin + end) / 2; //mid point
        recur(nums, begin, mid);   //[begin,mid]
        recur(nums, mid + 1 , end);//[mid + 1, end]

        //merge
        vector<int> tmp(end - begin + 1);//size of current interval

        //left pointer at first element of left sub interval, and right pointer at first element of right interval
        int lP = begin, rP = mid + 1;
        int i = 0;//index of temporary array

        while(lP <= mid || rP <= end)//runs until both pointer hits the end of its sub-interval
        {
            //if left pointer is not overbound, and right pointer is overbound, or right >= left
            if(lP <= mid && (rP > end || nums[lP] < nums[rP]))
                tmp[i] = nums[lP++];
            else
                tmp[i] = nums[rP++];
            ++i;
        }
        i = begin;
        for(auto&& ele : tmp)
            nums[i++] = ele;
    }

    vector<int> sortArray(vector<int>& nums) {
        recur(nums,0, nums.size() - 1);
        return nums;
    }
};