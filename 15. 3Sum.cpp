class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        
        sort(nums.begin(), nums.end());//首先对数据做出排序，这里开始复杂度已经是n^2了，后面不要超过n^2就好。
        
        /*我们现在负数在罪左边，正数在最右边，因为排序是从小到大的。
        这个时候要注意，这道题的目标是找出3个数加在一起是0
        
        A + B + C = 0  有哪些情况？
        
        当其中一个是0的时候，比如说B = 0，那么A 必须 = -C
        当其中一个是1的时候，比如说B = 1, 那么A + C必须是-1
        也可以理解为(A + B) = -C
        
        总之，这意味着3个数中至少有一个必须是负数，或者3个都必须是0，如果3个都是正数是行不通的。
        由于这个原因，考虑到数值已经被排序了，那么我们的循环实际上走到0的时候就可以停止了。
        
        因为当选中了-1的时候，就会去找0和1构成一个 -1 + 0 + 1 = 0
        所以只需要选中负数区域和0，然后再去找2个数来使3数相加等于0，就足以找出所有的组合了。
        
        */
    
        for(int i=0; i < nums.size(); i++)
        {
            if(i > 0 && nums[i] == nums[i - 1])//每个被选中的数字最多处理一次，因为排序过了，所以只要和上一个数字比较就可以了。
            {
                continue;
            }
            
            if(nums[i] > 0)
                break; // i 永远只能是负数或者       0，由于之前说过的原因。

            //当一个数选中了，这个问题就变成两数之和了。
            int target = -nums[i]; //寻找B + C = -A
            
            int rIndex = nums.size() - 1;
            //使用双指针做两数之和
            for(int lIndex = i + 1; lIndex < rIndex;++ lIndex)//相遇之前都要接着看
            {
                if(lIndex > (i + 1) && nums[lIndex] == nums[lIndex - 1])
                    continue;
                
                int needed = target - nums[lIndex];
                while(nums[rIndex] > needed && lIndex < rIndex)//如果右侧比我们需要的数大，我们就继续往左移，因为左边更小
                    --rIndex;
                
                if(lIndex == rIndex)
                    break;
                
                if(nums[rIndex] == needed)//找到了合适的组合
                {
                    vector<int> ans;
                    ans.emplace_back(nums[i]);
                    ans.emplace_back(nums[rIndex]);
                    ans.emplace_back(nums[lIndex]);
                    results.emplace_back(ans);
                    --rIndex;
                }

            }
        }
        return results;
    }
};