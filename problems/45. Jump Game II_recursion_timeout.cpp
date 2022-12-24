class Solution {
public:

    bool isReachable(int i,int j, int max_step)
    {
        //判定是否可以从j走到i
        //i: 目标位置,j:源,max_step:源支持最大走几步
        //如果i == j 需要 0 步， 如果 i = 2 j = 1，需要1步， 如果 i = 4 j = 2 ，需要2步
        return max_step >= i - j;
    }
    
    int _jump(int i, vector<int>& nums,int step) {
        if(i == 0)
            return step;
        
        int min_step = INT_MAX;
        for(int j = i - 1;j >= 0;j--)
        {
            if(isReachable(i,j,nums[j]))
            {
                min_step = min(min_step,  _jump(j, nums,step + 1) );
            }       
        }
        
        return min_step;
    }
    
    
    int jump(vector<int>& nums) {
        return _jump(nums.size() - 1, nums, 0);
    }
};