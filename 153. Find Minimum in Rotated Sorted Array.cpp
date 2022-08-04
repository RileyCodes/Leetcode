class Solution {
public:
    /*
    要找到被旋转过的数组里面的最小的数
    首先考虑012345，如果最左边比最右边小，直接返回最左边就可以了。
    只有450123这种需要找到最小在哪。
    
    由于约束：All the integers of nums are unique.，我们不需要担心4444，4501234这种情况。
    
    所以如果最左边不比最右边小，那么当我们找到的一个数大于等于最左边的时候，我们就应该向右搜索。
    如：450123，我们拿到了5，应该向右搜索。
    否则，我们拿到的数比最左边小的时候，如1，2,3,我们都应该向左搜索。
    一直这样持续直到左右指针相撞为止。
    */
    int findMin(vector<int>& nums) {
        if(nums[0] < nums[nums.size() - 1])
            return nums[0];
        
        int lP = 0, rP = nums.size() - 1;
        while(lP < rP)
        {
            int mid = (lP + rP) / 2;
            if(nums[mid] < nums[0])//mid比最左边小
                rP = mid - 1;
            else
                lP = mid + 1;
        }
        //跳出的时候，lP == rP必然成立。
        if(nums[lP] >= nums[0] && nums.size() > 1)
            return nums[lP + 1];//收缩到最小数字左边一个去了，往右边偏一下
        
        //否则就直接返回
        return nums[lP];
    }
};