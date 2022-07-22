class Solution {
public:    
    int search(vector<int>& nums, int target) 
    {    
        int lBound = 0, rBound = nums.size() - 1; 
        while(1)
        {
            int intervalLength = rBound - lBound;
            int mid = intervalLength / 2 + lBound;
            if(nums[mid] == target)
                return mid;     
            
            if(target < nums[mid])
            {
                if(mid - 1 < lBound)
                    return -1;
                rBound = mid - 1;
            }     
            
            if(target > nums[mid])
            {
                if(mid + 1 > rBound)
                    return -1;
                lBound = mid + 1;
            }            
        }
        return -1;
    }
};