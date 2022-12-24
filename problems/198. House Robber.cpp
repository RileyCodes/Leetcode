class Solution {
    
    int results[101]{[0 ... 100] = -1};
    
    int _rob(vector<int>& nums,int count)
    {
        if(results[count] != -1)
            return results[count];
        
        if(count <= 0)//第二户人家就是第0户人家+第2户人家，或者第1户人家，所以我们要考虑好0的情况。
            return 0;
        if(count == 1)
            return nums[0];

        int result = max(_rob(nums, count - 2) + nums[count - 1], _rob(nums, count - 1));
        results[count] = result;
        return result;
    }
    
public:
    int rob(vector<int>& nums) {
        /*
        可以发现，只有一户人家的时候，最优解是唯一这一户人家。
        两户人家的时候，选价值最高的哪个
        三户人家的时候，会出现比如说[4,5,4] 两户的结果最高价值是选5，但是这时候边上2个4被浪费掉了。
        这说明三户人家的最优解并不简单的是两户人家
        
        但是第三户人家的最优解似乎只有2个可能性，一个是 只有一户人家时的最优解+第三户
        还一个是两户人家的最优解，也就是4,4,或者5。
        
        再看看四户人家的情况，比如说[4,5,4,7]
        最优解是三户人家的最优解，或者2户人家的最优解 加上第四户。
        三户人家的最优解可能是：[4,4] 或者[5]
        两户人家的最优解可能是[4]或者[5] 加上[7] 
        */
        return _rob(nums, nums.size());
        
    }
};