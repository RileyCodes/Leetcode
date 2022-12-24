class Solution {
public:
    /*
    这道题要求找到指定数字的起始位置和结束位置（比如说[5,7,7,8,8,10] 需要我们找到 8在哪开始，在哪结束
    数组是已经被排序好了的。
    
    我们先从普通的二分查找开始，直到找到目标数字
    
    这个时候需要执行2个不同方向的二分，一个向左，一个向右，如果向左还是找到目标数字，那么就调小起始位置
    如果找到非目标数字，那么就从这个非目标数字的右侧到最后已知目标数字位置之间，继续取mid
    */
    
    struct bSearchInfo {int lP, rP , result; };
    
    bSearchInfo bSearch(vector<int>& nums, const int lP,const int rP,int target)
    {
        vector<int> result;
        bSearchInfo info;
        info.lP = lP;
        info.rP = rP;
        info.result = -1;    
        
        if(nums.size() == 0)
            return info;
        
        while(info.lP < info.rP)
        {
            int mid = info.lP  + (info.rP - info.lP) / 2;
            if(nums[mid] < target)//目标在右边
                info.lP = mid + 1;
            else if(nums[mid] > target)//目标在左边
                info.rP = mid - 1;
            else
            {
                info.result = mid;
                return info;
            }
        }
        if(info.lP == info.rP && nums[info.lP] == target)
        {
                info.result = info.lP;
                return info;            
        }

        return info;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        //开始二分查找
        int lP = 0;
        int rP = nums.size() - 1;
        bSearchInfo info =  bSearch(nums,lP,rP,target);
        int targetIndex = info.result;
        vector<int> result;
        
        if(targetIndex == -1)
        {
            result.emplace_back(-1);
            result.emplace_back(-1);
            return result;
        }

        int targetMinIndex = targetIndex;
        int targetMaxIndex = targetIndex;

        for(int leftIndex = targetMinIndex; leftIndex != -1; 
            leftIndex = bSearch(nums,info.lP,leftIndex - 1,target).result)
        {
            //开始寻找左边界，继续沿用之前的左边界，因为我们知道超过这个边界肯定是没有目标数字的、
            //右边界为当前已经发现的最左目标数字的左边

            if(leftIndex != -1)
                targetMinIndex = leftIndex;
        }
        
        for(int rightIndex = targetMaxIndex;rightIndex != -1;
           rightIndex = bSearch(nums,rightIndex + 1,info.rP,target).result)
        {
            if(rightIndex != -1)
                targetMaxIndex = rightIndex;
        } 
        
        result.emplace_back(targetMinIndex);
        result.emplace_back(targetMaxIndex);
       
        return result;        
    }
};