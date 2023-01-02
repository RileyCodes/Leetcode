class Solution {
public:

    int count = 0;

    void recur(vector<long long>& ps, int begin, int end, int lower, int upper) 
    {
         //nums = ps

        //if left bound is at or over right bound, return
        if(begin >= end)
            return;
        //std::cout << "begin: " << begin << ", end: " << end << ", lower: " << lower << ", upper: " << upper << std::endl;


        int mid = (begin + end) / 2; //mid point
        recur(ps, begin, mid, lower, upper);   //[begin,mid]
        recur(ps, mid + 1 , end, lower, upper);//[mid + 1, end]

        /* Despite that each sub-interval is sorted and its index has changed, 
        however, the right sub-interval will still have its index at least higher than the left sub-interval.
        Therefore, for any i, j, and j > i, if lower <= nums[j] - nums[i] <= higher, it implies there 
        exists a combination of range sum, and we should increment `count`. */


        int wndStart = mid + 1, wndEnd = mid + 1;
        for(int i = begin; i <= mid; ++i)   
        {
            while(wndStart <= end && ps[wndStart] - ps[i] < lower)
                ++wndStart;
            while(wndEnd <= end && ps[wndEnd] - ps[i] <= upper)
                ++wndEnd;

            count = count + (wndEnd - wndStart);
        }

        //merge
        vector<long long> tmp(end - begin + 1);//size of current interval

        //left pointer at first element of left sub interval, and right pointer at first element of right interval
        int lP = begin, rP = mid + 1;
        int i = 0;//index of temporary array

        while(lP <= mid || rP <= end)//runs until both pointer hits the end of its sub-interval
        {
            //if left pointer is not overbound, and right pointer is overbound, or right >= left
            if(lP <= mid && (rP > end || ps[lP] < ps[rP]))
                tmp[i] = ps[lP++];
            else
                tmp[i] = ps[rP++];
            ++i;
        }
        i = begin;
        for(auto&& ele : tmp)
            ps[i++] = ele;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> ps;
        ps.resize(nums.size() + 1);
        
        for(int i = 0; i < nums.size(); ++i)
            ps[i + 1] = ps[i] + (long long)nums[i];

        recur(ps, 0, ps.size() -1, lower, upper);

        return count;
    }
};