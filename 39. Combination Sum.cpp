class Solution {
public:
    
    /*
    这道题给出了一堆数字的数组，每个数组里面数字都不一样，我们要找到所有加在一起等于target的组合。
    注意：同一个数字可以用多次

    Input: candidates = [2,3,6,7], target = 7
    Output: [[2,2,3],[7]]
    
    Input: candidates = [2,3,5], target = 8
    Output: [[2,2,2,2],[2,3,3],[3,5]]
    
    我们拿着一个数，可以用除法确定这个数的多少倍可以等于或者小于target
    比如说target = 5 我们拿着3。 5 / 3 = 1，这时候会发现 3 * 1 = 3而 5 - 3 = 2
    因此，我们的组合还需要一个2
    
    又比如说target = 5 我们拿着1。 5 / 1 = 5，这时候发现 1 * 5 = 5，得出有效组合[1,1,1,1,1]
    
    看看candidates = [2,3,5], target = 8
    从大到小处理, 8 - 5 = 3，得到[5,3]
    3 - 2 = 1，我们没有1，忽略(此处应有二分查找？)
    8 - 2 = 6, 6 / 2 = 3 得出[2,2,2,2]
    8和其他数的组合处理完了，开始看3
    8 / 3 = 2, 8 - (3 * 2) = 2，我们还需要一个2,得到[3,3,2]
    
    根据以上数据，似乎可以得出一个结论，如果我们选中了数字A：
    
    如果 (target / A)  == 0 数字A太大，是个无效组合。
    
    如果 (target / A)  >= 1 但是 A != target，那么就说明 A < target；
    我们还需要一个更小或者相等的数字才能形成有效组合（对排序的数据做单向二分查找？
    
    A = 7的情况下，8/7 == 1 ,A != target 需要相同大小或者更小的另一个数（最大是1）
    A = 4的情况下 8/4 = 2, A != target，需要相同大小或者更小的另一个数（最大的可以是相同的4）
    
     如果 (target / A)  == 1 且 A == target，
     比如说taget == 8 A = 8 的情况下,8/8 = 1，A == target 我们找到的数就是组合本身。
     
     如果我们从大到小一个个找出所有的组合，最终出来的似乎就是答案。
    */
    
    
    void _combinationSum(vector<int>& candidates, int target,vector<int>& ans_prefix, 
                         vector<vector<int>>& result, int maxIndex)
    {
        for(int i = maxIndex; i >= 0; --i)//从大到小处理。
        {
            int div = target / candidates[i];
            if(div == 0)//i比tartget大，忽略
                continue;
            
            if(target == candidates[i])
            {
                //对于刚好一样的情况下，不可能会有别的组合了，加入答案以后这个数就处理完成了
                vector<int> ans = ans_prefix;
                ans.emplace_back(candidates[i]);
                result.emplace_back(ans);
                continue;
            }
            
            //当代码走到这里的时候，意味着 div >= 1 且div != target
            //div 是可行解中最大的倍数，我们从最大倍数到一个个试。
            //为什么不能只看最大倍数？ 比如说目标是7 我们有3和2的时候，3的最大可行倍数是3 * 2 = 6，然而6+2 = 8。
            //因此，我们也需要检查更小的倍数。
            for(int j = div; j >=1;j--)
            {
                vector<int> ans = ans_prefix;//每个答案基于上一级已经计算出的答案
                //这个ans必须是本地的局部变量 因为我们试过某个倍数以后，下一个倍数的答案不能被上一个倍数的答案影响。
                
                int got = j * candidates[i];//got是被选中的数字的倍数，从最大可行倍数到1都试试。
                int need = target - got;//这是我们缺少的数
                for(int k = 0; k < j; ++k)//先把倍数作为答案的一部分加进去。
                {
                    ans.emplace_back(candidates[i]);
                }
                if(need == 0)//我们不缺少数了，加答案
                {
                    result.emplace_back(ans);
                    continue;                
                }

                //我们应该意识到，当存在剩下的数的时候，剩下的数的组合可能会有好几种，因此递归函数返回的应该是多个答案。
                //此外，我们需要的最大的数不会超过剩下的数，而且剩下的数不会是i（否则就是倍数了）
                //所以下一轮递归只需要看[0,i -1]这个范围。
                //这是因为比如说我们拿着5的时候，就已经考虑过5 + 3 这种组合了
                //所以拿着3的时候就没必要去考虑3 + 5 这种组合了，反而会导致重复答案。
                _combinationSum(candidates, need, ans, result,i - 1);                   
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> result;
        sort(candidates.begin(),candidates.end());
        vector<int> ans;
        _combinationSum(candidates, target,ans , result, candidates.size() - 1);

        return result;
    }
};