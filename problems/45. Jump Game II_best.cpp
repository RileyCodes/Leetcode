class Solution {
public:
    int jump(vector<int>& nums) {
         //这道题要求我们找出跳跃次数最小的，从数组最左边走到最右边的办法。
        
        //在一开始，我们能走到的最远位置就是[0]的值
        //我们发现的上一个最大的元素索引也是0
        //在这个时候，我们只选择了一个数
        int maxReach = nums[0];
        int lastMaxIndex = 0;
        int depth = 1;

        //虽然我们选择了一个数，但是如果一开始就在目的地，选择的这个数是没用的，所以返回0
        if(nums.size() == 1)
            return 0;
        
        
        //每次循环的时候，i选中lastMaxIndex
        //因为我们已经找到了当前选中的元素的可行空间内可以给我们带来最大值的值和对应的索引，选中这个索引
        for( int i = 0; ;i = lastMaxIndex)
        {
            //i本身已经抵达目的地了，直接返回
            if(maxReach >= nums.size() - 1)
            {
                return depth;
            } 
            
            //检查nums[i]可以带我们去的所有位置
            //假设 i = 0, nums[0] = 7 这意味着我们最多可以往右走7步，抵达[7]
            //i + nums[i] == 7        
            for(int j = i + 1; j <= i + nums[i]; ++j)
            {

                int localMax = j + nums[j];//当前空间内选中的元素可以带我们去的最大位置。
                if(localMax > maxReach)
                {
                    //在可行空间内找到了更大的的本地最优解，记录新的最大空间和带来这个空间的元素索引
                    maxReach = localMax;
                    lastMaxIndex = j;
                }

                //在这个过程中，如果我们可以抵达的终点已经在可以去的空间里了，就没必要比较后面的了
                if(maxReach >= nums.size() - 1)
                    break;               
            }
        
            ++depth; //增加路径长度1             
            //在i可以抵达的可行空间内有一个数可以抵达目的地，这种情况depth要多一个（因为我们多用了一个数）
            if(maxReach >= nums.size() - 1)
                return depth;
        }

        return -1;//???
    }
};