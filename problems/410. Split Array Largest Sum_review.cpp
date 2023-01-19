class Solution {
public:

    bool isFit(vector<int>& nums, int limit,int k)
    {
        int cnt = 0;
        int i = 0;
        while(i < nums.size())
        {
            if(cnt + nums[i] <= limit)
            {
                cnt += nums[i];
                ++i;
            }
            else
            {
                --k;
                cnt = 0;
                if(k == 0)
                    return false;
            }
            
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i)
            sum += nums[i];
        
        int low = 0, high = sum + 1;
        int lowestFind = INT_MAX;

        while(low < high)
        {
            int mid = (low + high) / 2;

            bool res = isFit(nums, mid, k);
            if(res)
            {
                lowestFind = min(lowestFind, mid);
                high = mid;
            }
            else
                low = mid + 1;
        }
        return lowestFind ;
    }
};