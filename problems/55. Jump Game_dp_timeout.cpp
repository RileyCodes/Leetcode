class Solution {
public:
    /*
    这道题问给出一个整型数组nums，我们一开始位于数组的最左边
    每一个元素代表了我们可以在该位置最多跳多远。
    
    动态规划 - 最后一步 -> 更小规模子问题 -> 状态转移方程 -> 初值与边界条件
    
    最后一步：  最后一步我们位于某个元素 i，其可以抵达最右边，且我们可以从最左边抵达这个元素 i
    
    更小规模子问题：我们能不能抵达 元素 i？
    
    状态转移方程：
    我们的状态是f，代表其可以被最左边抵达。
    如果f[j] 可以被f[i]抵达，也就是(j - i) <= f[i] : j 和 i之间的距离小于等于f[i]可以条约的距离
    其中i的范围可以是从0到 j - 1
    
    也就是说，f[j] = any (from 0 to j -1 where f[i] == true and (j - i) <= f[i])
    
    初值：
    f[0] 代表最左边，我们一开始就在最左边，无条件为true。
    
    */
    bool canJump(vector<int>& nums) {
        int f[nums.size()];
        f[0] = true;
        
        for(int i = 1; i < nums.size();++i)
        {
            bool flag = false;
            for(int j = 0; j < i ;++j)
            {
                if(f[j] && (i - j) <= nums[j])
                {
                    flag = true;
                    break;
                }                    
            }
            f[i] = flag;
        }
        return f[nums.size() - 1];
    }
};