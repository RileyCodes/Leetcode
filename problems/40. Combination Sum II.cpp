class Solution {
    
public:
    /*
        这道题要求给出一堆数字，找出使用这些数字加在一起等于target的所有组合。
        需要注意的是，给我们的每个数字最多只能用一次，比如说[1,1]，每个1只能用一次。
        
        Input: candidates = [10,1,2,7,6,1,5], target = 8
        Output: 
        [
        [1,1,6],
        [1,2,5],
        [1,7],
        [2,6]
        ]
        
        Input: candidates = [2,5,2,1,2], target = 5
        Output: 
        [
        [1,2,2],
        [5]
        ]
        
        这道题实际上存在2个约束条件，一个是数组中每个元素在同一个组合内只能用一次
        除此之外，我们还需要排除掉看上去同样的组合
        比如说candidates = [2,5,2,1,2], target = 5 中,[1,2,2]可以有多个，因为数组中一共有3个2
        但是因为不论是[0]还是[2]的[2,2]，还是[2]和[4]的[2,2]看上去都一样，因此我们只能记录其中一个组合。
        
        对于这种A,A'的重复数字的情况，根据前面几道题，可以想到我们可能需要对数据排序。
        在排序之后，使用二进制法对所有组合遍历，只记录加在一起等于target的就可以了。
        但是这样做似乎不是最优解，比如说target是 8的情况下，我们可以直接忽略 > 8的数组区间
        因此，我们应该从大到小遍历的时候，每次只检查[0,i]之间的组合，因为 > i的区间已经被检查过了。
        
    */
    void _combinationSum2(vector<int>& candidates, int target, int maxIndex, vector<int> combination,
                                        vector<vector<int>>& results)
    {
        if(target < 0)
            return;
        if(target == 0)
        {
            results.emplace_back(combination);
            return;
        }
        //从大到小处理数字
        int lastNum = -1;//-1代表没有lastNum。
        for(int i = maxIndex; i >= 0; --i)
        {
            //排除重复数字，因为排序过了，遇到和上一个重复的忽略即可。
            //这里的套路和47. Permutations II
            if(lastNum == candidates[i])
                continue;
            lastNum = candidates[i];
            
            vector<int> new_combination = combination;
            new_combination.emplace_back(candidates[i]);
            _combinationSum2(candidates, target - candidates[i], i - 1,new_combination, results);
        }
                    
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> results;

        _combinationSum2(candidates, target, candidates.size() - 1, vector<int>() , results);

        return results;
    }
};