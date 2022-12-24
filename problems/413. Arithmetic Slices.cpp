class Solution {
public:
    
    /*
    等差数列指的是一个至少有3个元素的数组，且任何连续的元素之间互相做减法出来的结果都一样的。 
    我们得到了一个整数数组，我们需要计算出有多少个符合这种条件的子数组。
    */
    int addCount(int width)
    {
        //假设我们有[1,2,3,4,5,6] 宽度是 6 - 0 = 6。 我们的滑动窗口分别会是6,5,4,3，刚好4个，所以是6 - 3 + 1
        int slideWindowCount = width - 3  + 1; 
        if(slideWindowCount > 0)
            return ((slideWindowCount * (slideWindowCount + 1)) / 2);
        return 0;
    }
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int count = 0;
        if(nums.size() < 3)
            return 0;
        
        //我们首先用2个变量记录等差数列的起始和结束位置
        int begin = 0;
        int end = -1;
        int lastDiff = nums[1] - nums[0];
        for(int i = 1; i < nums.size() - 1;++i)
        {
            int diff = nums[i + 1] - nums[i];

            if(lastDiff != diff)
            {
                //这里开始差对不上了，是等差数列的结束在i - 1
                end = i + 1;
                int width = end - begin;//当前找到的等差数列的宽度。

                count += addCount(width);
                
                //下一个等差数列至少是从i开始的。
                begin = i;
            }
            else
                end = i + 1;
            lastDiff = diff;
        }
        
        //重复代码，处理循环跑完了 没出现lastDiff != diff的情况。
        //因为已经有宽度限制了，所以我们不需要考虑edge case.
        int width = end - begin + 1;//当前找到的等差数列的宽度。
        count += addCount(width);
        
        return count;
    }
};
