class Solution {
public:

    bool isSplitable(vector<int>& nums, int k, int arrMax)
    {
        int arrCnt = 1;
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(sum + nums[i] > k)
            {
                if(nums[i] > k)
                    return false;
                ++arrCnt;
                sum = nums[i];
                if(arrCnt > arrMax)
                    return false;
                continue;
            }
            sum += nums[i];
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {

        int lP = INT_MAX, rP = 0;

        for(auto&& num : nums)
        {
            rP += num;
            lP = min(lP, num);
        }

        ++rP;
        int ans = INT_MAX;
        while(lP < rP)
        {
            int mid = (lP + rP) / 2;
            if(isSplitable(nums, mid, k))
            {
                ans = min(ans, mid);
                rP = mid;
            }
            else
            {
                lP = mid + 1;
            }
        }

        return ans;    
    }
};