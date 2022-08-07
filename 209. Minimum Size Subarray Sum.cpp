class Solution {
public:
    
    /*
        这道题给出一个数组和一个数，要求找出相加以后大于等于目标数，且长度最小的连续子数组的数组长度。
        比如说target = 7, nums = [2,3,1,2,4,3]，答案就是2，因为[4,3] = 7
        
        可以想到的是，可以把所有加在一起大于等于target的子数组找出来，然后再一个个比较找出最小的子数组
        
        但是这么做空间复杂度并不是O(1)
        
        假设[1,2,3,4,999,6] 从右到左收缩，发现[1,2,3,4] 小于target而[1,2,3,4,999]大于target，因此认为最小是[1,2,3,4,999]是不行的。
        因为target就是999
        
        设target = x
        如果 a + b < x, a + b + c >= x 而 c < x，那么很明显 a + b + c是最小组合。
        
        这里面似乎有个规律，如果 a + b + c + d < x， 那么不管是 a + b ,b + c, c + d还是 a + b + c，都肯定小于 x
        但是如果a + b + c + d >= x，那么a b c d的任何组合都有可能 >= x
        
        如果我们用滑动窗口搞，发现
        [a] < x 
        [a,b] < x
        [a,b,c] < x
        [a,b,c,d] >= x
        这时候我们仍然可以肯定[a,b,c]的任何组合都 < x
        但是d本身，或者d和a,b,c中的一个或多个结合以后就可能 > x
        此时我们可以肯定的是我们找到的最小数组长度是4，但是也有可能最小是2。
        
        现在，我们收缩左侧指针，发现 [b,c,d]  >=x [c,d] < x 发现了最小数组长度可以是3
        由于我们要求连续数组，所以不需要考虑[b,d]这个组合。
        也不需要考虑[b,c]这个组合，因为之前已经知道了[a,b,c] < x，因此[b,c] 必然小于 x
        
        如果我们发现 [a] >= x 那么直接长度就是1
        但是如果 满足 >= x的组合不止一个呢？
        比如说target是 100，我们有[14,16,30,50,1,49,2,101]
        可以发现，满足 >= 100的组合有14 + 16 + 30 + 50 = 110 (4)
        50 + 1 + 49 = 100 (3) , 101(1)
        
        首先我们会发现 14 + 16 + 30 + 50 >= 100
        收缩发现别的都 < 100。
        收缩到50以后，右指针向右扩张，发现50 + 1 + 49 >= 100
        左指针向右收缩，走到49。
        右指针向右，发现49 + 2 + 101 >= 100
        左指针收缩，发现 101 >= 100
        答案就出来了。
        
    */
    int minSubArrayLen(int target, vector<int>& nums) {
        int lP = 0, rP = 0;
        int sum = 0;
        int minArrLen = INT_MAX;
        while(rP < nums.size())
        {
            sum += nums[rP];
            while(sum >= target && lP <= rP)//如果够大了，就试着记录当前找到的数组长度，并且试图缩小滑动窗口
            {
                minArrLen =  min(minArrLen, (rP - lP + 1));
                sum -= nums[lP];
                ++lP;
            }
            
            ++rP;
            
        }
        return minArrLen == INT_MAX? 0 : minArrLen;
    }
};