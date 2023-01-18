class Solution {
public:

    int maxCrossingMid(vector<int>& nums, int left,int right)
    {
        if(left > right)
            return INT_MIN;
        int mid = (left + right) / 2;

        int sumLeft = 0;
        int maxLeft = INT_MIN;
        int maxLeftAt = -1;
        for(int i = mid; i >= left; --i)
        {
            sumLeft += nums[i];
            if(sumLeft >= maxLeft)
            {
                maxLeft = sumLeft;
                maxLeftAt = i;
            }
        }

        int sumRight = 0;
        int maxRight = INT_MIN;
        int maxRightAt = mid;
        for(int i = mid + 1; i <= right; ++i)
        {
            sumRight += nums[i];
            if(sumRight >= maxRight)
            {
                maxRight = sumRight;
                maxRightAt = i;
            }
        }        

        return maxLeft + maxRight;
    }

    int recur(vector<int>& nums, int left, int right)
    {
        if(left > right)
            return INT_MIN;
        if(left == right)
            return nums[left];
        int mid = (left + right) / 2;
        int leftRes = recur(nums,left, mid);
        int rightRes = recur(nums, mid + 1, right);
        int midRes = maxCrossingMid(nums, left, right);
        
        if(leftRes > rightRes)
        {
            if(leftRes > midRes)
                return leftRes;
            return midRes;
        }
        else
        {
            if(rightRes > midRes)
                return rightRes;
            return midRes;
        }
        return INT_MIN;
    }

    int maxSubArray(vector<int>& nums) {;
        return recur(nums, 0, nums.size() - 1);
    }
};