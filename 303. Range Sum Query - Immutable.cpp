class NumArray {
public:

    vector<int> prefixSum;
    NumArray(vector<int>& nums) {

        prefixSum.emplace_back(nums[0]);
        for(int i = 1; i < nums.size(); ++i)
        {
            prefixSum.emplace_back(prefixSum[i - 1] + nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0)
            return prefixSum[right];

        return  prefixSum[right] -  prefixSum[left - 1];
    }
};