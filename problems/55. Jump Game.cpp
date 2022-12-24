class Solution {
public:
    /*
    [2,3,1,1,4,1,2,2,0]
    首先看有哪些可以到0
    [2,3,1,1,4,1,2,2,0]
             x   x
    发现4，2可以直接到0.
    
    看哪些可以到2
    
    [2,3,1,1,4,1,2,2,0]
               x
    可以到2
    再看哪些可以到1
    
    [2,3,1,1,4,1,2,2,0]
       x
    没有东西可以到3，此路不通。
    
    看哪些可以到4
    
    但是要注意，数组中的数值代表的可以最大跳几格，而不是只能跳几格，如果超过了，是可以少跳几格抵达目的地的。
    
    所以如果我们需要抵达i，那么i - 1只要大于 0就行
    i - 2 只要大于 1就行
    i - 3 只要大于 2就行。

    不过，这并不意味着我们的计算变复杂了，我们知道从i - 2 到 i 只要2步，只需要判断[i - 2] >= 2即可，而不是需要一步步尝试第几步能到。
    因此，这对问题的性质没有影响。
    
    我们从右到左找到能到i的节点，然后再找能到这个节点的节点，再找能到这个节点的节点的节点...直到找不到，或者找到起点为止。
    
    如果找不到，就找第二个能到i的节点，rinse and repeat...
    */
    
    bool isReachable(int i,int j, int max_step)
    {
        //判定是否可以从j走到i
        //i: 目标位置,j:源,max_step:源支持最大走几步
        //如果i == j 需要 0 步， 如果 i = 2 j = 1，需要1步， 如果 i = 4 j = 2 ，需要2步
        return max_step >= i - j;
    }
    
    bool _canJump(int i, vector<int>& nums) {
        if(i == 0)
            return true;
        
        for(int j = i - 1;j >= 0;j--)
        {
            if(isReachable(i,j,nums[j]))
            {
                //找到了一个可以抵达 i的index，如果这个index不是0，那么应该继续往左找什么index可以抵达这个index
                if(j == 0)
                    return true;
                
                return _canJump(j, nums);
            }       
            //如果行不通，继续循环看看前面有没有能从0跳到i的别的中间index
        }
        
        return false;
    }
    

    bool canJump(vector<int>& nums) {
        return _canJump(nums.size() - 1, nums);
    }
};