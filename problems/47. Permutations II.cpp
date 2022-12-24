class Solution {
public:
    /*
    这道题和Permutations I 类似，但是不同之处是我们可能会遇到重复的数字
    如以前的[1,2,3]，对于已经选择了1的情况下，可以有[1,2,3]和[1,3,2]
    但是在这道题，我们会遇到[1,2,2]这种情况，选择了1的情况下只有[2,2]这一个选项。

    我们首先会把数组排序，因为排序的复杂度低于生成组合，这不影响时间复杂度。
    
    在选择了1的情况下，下一级已经知道选择了1，所以选择2
    把组合的选择想象成3个空，第一级选择了1，安排下一级选2，taken里面是1 2
    下一级发现1 2被拿了，可选项只剩下2 安排下下级选2，得到[1,2,2]
    现在，第三级没有任何可以安排的东西，而第二级已经把唯一能安排的2安排掉了，回到第一级
    第一级知道，在选择了1的情况下，我们又选过了2，再选择2'和选2是一样的，没有意义，所以到此为止。
    而对于第一级本身来说，选过了1，现在选2是有意义的，选择2：[2]
    然后第二级选1,[2,1]
    第三级只能选2,[2,1,2']
    现在第三级所有可选项用过了，返回第二级，第二级选过1，可以选2：[2,2',1]
    由于第一级拿着2，第二级选过1和2'了，没有别的选择，返回第一级
    第一级发现2和2'是一回事，选择没有意义，算法结束。
    
    再看看[1,2,2',3]
    [1,2,2',3],[1,2,3,2'](从2'变到3是可以接受的)
    [1,3,2,2'](从2变到2'不可接受，因为是一样的 所以我们直接跳过2'，把[1]变成了3)
    这个时候对于[2]，从2变到2'也是不可接受的，直接进入第一级了。
    对于[0],从1变成2是可以接受的，于是我们有[2,1,2',3],[2,1,3,2'][2,2',1,3],[2,2',3,1]
    对于[1]，2'变成2没有意义，于是变成3，有了[2,3,2',1]
    以此类推，可以看到关键在于，在排序以后，某一位在变化的时候，必须不能从a变成a'，而必须要变成不同的数。
    */
    
    void dfs(vector<int>& nums, vector<vector<int>>& results,vector<int> taken)
    {
        int lastSelected = -11;//约束是-10到10,-11代表没选择任何东西。
        bool has_next_level = false;
        for(int i =0; i < nums.size(); ++i)
        {
            bool isTaken = false;
            for(int j = 0; j < taken.size(); ++j)
            {
                if(taken[j] == i)//如果被选中的数字已经被拿了
                    isTaken = true;
            }
            if(isTaken)
                continue;
            
            if(nums[i] == lastSelected)//如果我们之前已经选过同一个数字（重复数字）
                continue;
            
            lastSelected = nums[i];
            vector<int> next_taken = taken;
            next_taken.emplace_back(i);//本级不被影响，刚拿走的数字只交给下一级
            dfs(nums,results,next_taken);
            has_next_level = true;
        }
        if(!has_next_level)//如果没有下一级了，那么就加入答案
        {
            vector<int> ans;
            for(int j = 0; j < taken.size(); ++j)
            {               
                ans.emplace_back(nums[taken[j]]);
            }
            results.emplace_back(ans);
        }
    }
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> results;
        dfs(nums,results,vector<int>());
        return results;
    }
};