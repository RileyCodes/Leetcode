class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lBound = 0, rBound = nums.size() - 1;
        while(rBound - lBound >= 0)
        {
            int mid = ((rBound - lBound) / 2) + lBound;
            if(nums[mid] == target)
                return mid;
            
            if(nums[mid] > target)// go left
                rBound = mid - 1;
            else
                lBound = mid + 1;
        }

        return lBound;
    }
};