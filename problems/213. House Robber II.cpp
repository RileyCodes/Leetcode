class Solution {
public:
    /*
    对于这道题的基础版本，我们知道只有第一个房子的时候，最优解是第一个房子
    只有2个房子的时候，最优解是第一个或者第二个房子
    有3个房子的时候，如果我们选了第三个房子，那么我们能抢到的钱就是第一个房子的最优解加上第三个房子的价值
    如果我们不选第三个房子，我们能抢到的钱就是第二个房子的最优解。
    
    也就是说，如果我们选择了房子i，那么我们的钱就是i + 最优解[i - 2]。 
    如果我们选择了房子i - 1，那么我们的钱就是最优解[i - 1]
    */
    
    
    /*
    int _rob_with_first(vector<int>& nums, int k, vector<int>& data)
    {
        if(k == 0)//偷[0,0]家房子的最优解就是这个房子本身
            return nums[k];
        if(k == 1)//偷[0,1]家房子的最优解就是价值最高的房子
            return max(_rob_with_first(nums, k - 1,data), nums[k]);
        
        if(data[k] != -1)
            return data[k];
        
        //偷[0,k]家房子的最优解就是k - 2的最优解加上 k的价值 或者 k- 1 的最优解。
        //对于抢了第一家的情况，我们必须忽略最后一家。
        int res = max(_rob_with_first(nums, k - 2,data) + (k == nums.size() - 1? 0 : nums[k]), 
                 _rob_with_first(nums, k - 1,data));
        data[k] = res;
        return res;
    }*/
    
    /*
    int _rob_without_first(vector<int>& nums, int k,vector<int>& data)
    {
        if(k == 0)//不抢第一家
            return 0;
        if(k == 1)//不抢第一家，在只有两家的情况下最优解只能是第二家
            return nums[k];
        
        if(data[k] != -1)
            return data[k];
                
        //偷[0,k]家房子的最优解就是k - 2的最优解加上 k的价值,或者k-1的最优解。
        int res = max(_rob_without_first(nums, k - 2,data) + nums[k], _rob_without_first(nums, k - 1,data));
        data[k] = res;
        return res;
    }    */
        
    int rob(vector<int>& nums) {
        int k = nums.size() - 1;
        vector<int> with_first(nums.size() + 1);
        vector<int> without_first(nums.size() + 1);
        
        with_first[1] = nums[0];
        without_first[1] = 0;
        //迭代法：从第二户开始
        for(int k = 2; k <= nums.size(); ++k)
        {
            //k - 2户 加上 k户  或者 k - 1户
            //如果k户是最后一户，算0
             with_first[k] = max(with_first[k - 2] + (k == nums.size()? 0 : nums[k - 1]), 
                 with_first[k - 1]);
        }
        
        for(int k = 2; k <= nums.size(); ++k)
        {
            //k - 2户 加上 k户  或者 k - 1户
            //如果k户是最后一户，算0
             without_first[k] = max(without_first[k - 2] + nums[k - 1],  without_first[k - 1]);
        } 
        
        return max(with_first[nums.size()],without_first[nums.size()]);
    }
};