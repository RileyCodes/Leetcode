class Solution {
public:
    int search(vector<int>& nums, int target) {
        //首先找到至少哪个数以前没有跑到另一头去
        int maxUnrotatedNum = nums.size() - 1;//这是最右边的一个数，小于等于这个数的都没跑到另一头去
        int minRotatedNum = nums[0];//这是最左边第一个数，大于等于这个数的都跑到另一头去了，除非这个数组没被rotate过。
        
        //开始二分查找
        int lP = 0, rP = nums.size() - 1;
        
        while(lP < rP)
        {
            int mid = (lP + rP) / 2;//代数变换出来的，原始形态是lP + (rP - lP) / 2
            
            if(nums[mid] == target)//如果已经找到了，直接返回
                return mid;
            
            //那么我们二分查找的时候，遇到比target小的仍然不必定向右走
            //比如说45670123，目标是7，我们mid是0或者6的分别要往左边或者右边走
            //目标是7，我们手里发现了0，0小于4，这这种情况要往左走
            //目标是7，我们手里发现了5，5大于4，这种情况正常走（往右走）
            
            if(target >= minRotatedNum)
            {
                if(nums[mid] < target)//我们手里的比目标小，正常要往右走
                {
                    if(nums[mid] < minRotatedNum)//向左走
                        rP = mid - 1;
                    else 
                        lP = mid + 1;
                }   
                //比目标大，回顾45670123 如果目标在左边
                //（即4567，那么就不可能遇到mid在右边，而且比目标大的情况，所以这种时候正常处理就好了。
                else
                    rP = mid - 1;
            }
            else //要找的数靠右了 比如说:4560123 我们要找到的是2
            {
                //如果比目标小，由于要找的数必然在0123，比目标小就肯定要往右走
                if(nums[mid] < target)//我们手里的比目标小，正常要往右走
                    lP = mid + 1;
                else
                {
                    //对于比目标大，有两种可能性，4560123，要找到1，你有可能mid是456 也有可能是23
                    //判断如果mid >= 4 那么就往右走，否则就可以正常处理
                    if(nums[mid] >= minRotatedNum)
                        lP = mid + 1;//往右走
                    else
                        rP = mid - 1;//往左走
                }
            }    
        }
        
        if(lP == rP && nums[lP] == target)
            return lP;
        
        return -1;//前面各种条件没找到东西返回那就是没找到。
    }
};