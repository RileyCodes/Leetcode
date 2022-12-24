class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int lP = 0, rP = nums.size();

        int leftBound = -1;
        while(lP < rP)
        {
            int mid = (lP + rP) / 2;
            if(nums[mid] > target)
                rP = mid;
            else if(nums[mid] < target)
                lP = mid + 1;
            else if(nums[mid] == target)
            {
                rP = mid;
                leftBound = mid;
            }
        }

        lP = 0; rP = nums.size();

        int rightBound = -1;
        while(lP < rP)
        {
            int mid = (lP + rP) / 2;
            if(nums[mid] > target)
                rP = mid;
            else if(nums[mid] < target)
                lP = mid + 1;
            else if(nums[mid] == target)
            {
                lP = mid + 1;
                rightBound = mid;
            }
        }        

        ans.emplace_back(leftBound);
        ans.emplace_back(rightBound);
        return ans;
    }
};