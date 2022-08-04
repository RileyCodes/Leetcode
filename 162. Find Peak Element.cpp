class Solution {
public:
    
    /*
    这道题我们要找到一个数，比另外2个数都要大（局部峰值）
    输入有array[n - 1] != array[n]的设定。
    也就是说，2个元素之间要么是在递增，要么是在递减，不会不变。
    其中，越界的可以被视为深渊，比如说数组[1,2,3,4,5,6]，6是峰，因为越过6就是深渊了。
    
    我们只需要找到其中一个峰值就可以，不需要全部找到。
    
    这道题可以直接用二分查找做。每次mid会判断左右那边大，如果mid遇到左边小右边大，左指针就会指向（右移）到这个右边大。
    如果mid遇到左边大右边小， 那么右指针就会指向（左移）到这个左边大
    
    通过这样不断缩小范围，会以log(n)的步骤收缩到一个峰上。
    
    */
    int findPeakElement(vector<int>& nums) {
        int lP = 0, rP = nums.size() - 1;
        
        while(lP < rP)
        {
            int mid = (lP + rP) / 2;
            
            bool isLeftLower = false;
            if(mid - 1 < 0)//越界的都是深渊，会比当前更低
                isLeftLower = true;
            else
                isLeftLower = nums[mid] > nums[mid - 1];
            bool isRightLower = false;
            if(mid + 1 >= nums.size())
                isRightLower = true;
            else
                isRightLower = nums[mid] > nums[mid + 1];
            
            if(isLeftLower && isRightLower)//左右都小，找到了峰
                return mid;
            else if(isLeftLower)
                lP = mid + 1;
            else if(isRightLower)
                rP = mid - 1;     
            else//找到了局部极小值，往哪走都行。
                lP = mid + 1;
            
        }
        return lP;
    }
};