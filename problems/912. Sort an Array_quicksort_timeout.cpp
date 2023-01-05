class Solution {
public:

    int part(vector<int>& nums, int lo, int hi)
    {
        int& p = nums[lo];
        int i = lo + 1;
        int j = hi;
        while(i <= j)
        {
            while(i < hi && nums[i] <= p)
                ++i;
            while(j > lo && nums[j] > p)
                --j;
            if(i >= j)
                break;
            swap(nums[i], nums[j]);
        }
       
        swap(p, nums[j]);
        return j;
    }

    void recur(vector<int>& nums, int lo, int hi) 
    {
        if(lo >= hi)
            return;
        int p = part(nums,lo, hi);
        
        recur(nums, lo , p - 1);
        recur(nums, p + 1, hi);
    }

    vector<int> sortArray(vector<int>& nums) {

        for(int i = 0; i < nums.size(); ++i)
        {
            swap(nums[i], nums[rand() % nums.size()]);
        }

        recur(nums,0, nums.size() - 1);
        return nums;
    }
};