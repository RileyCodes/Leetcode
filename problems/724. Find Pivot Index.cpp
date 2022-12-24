class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftsum[nums.size()];
        int rightsum[nums.size()];
        
        leftsum[0] = nums[0];
        for(int i = 1 ; i < nums.size(); ++i)
        {
            leftsum[i] = leftsum[i - 1] + nums[i];
        }
        
        rightsum[nums.size() - 1] = nums[nums.size() - 1];
        
        for(int i = nums.size() - 2; i >= 0;--i)
        {
            rightsum[i] = rightsum[i + 1] + nums[i];
        }
        
        if(nums.size() == 1)
        {
            return 0;
        }
        
        if(rightsum[1] == 0)
        {
            return 0;
        }        
        
        int lP = 0;
        while(lP + 2 < nums.size())
        {
            if(leftsum[lP] == rightsum[lP + 2])
                return lP + 1;
            
            ++lP;
        }
        
        if(leftsum[nums.size() - 2] == 0)
        {
            return nums.size() - 1;
        }                
        

        
        return -1;
    }
};