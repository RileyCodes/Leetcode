class Solution {
public:
    int _search(vector<int>& nums,int target, int lBound,int rBound)
    {
        int intervalLength = rBound - lBound;
        int mid = intervalLength / 2 + lBound;
        if(nums[mid] == target)
            return mid;
        
        if(target < nums[mid])
        {
            if(mid - 1 < lBound)
                return -1;
            return _search(nums,target,lBound, mid - 1);
        }
            
        if(target > nums[mid])
        {
            if(mid + 1 > rBound)
                return -1;
            return _search(nums,target,mid + 1, rBound);           
        }
        return -1;
    }
    
    
    int search(vector<int>& nums, int target) {
        return _search(nums,target,0, nums.size() - 1);
    }
};