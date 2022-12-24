class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        int taken[nums.size()];
        const int not_selected = -11;
        taken[0] = not_selected;
        int cur = 0;//当前指向第几位
        int index[nums.size()]; //每一位都处理到了第几个组合
        index[0] = 0;
        vector<int> ans(nums.size());
        
        while(cur >= 0)
        {
            //先判断当前选中的数是否被拿着
            if(cur >= nums.size() || index[cur] >= nums.size())//如果已经越界了
            {
                if(cur < nums.size())//往前退的时候，把taken释放掉
                    taken[cur] = not_selected;
                cur--;//那么就移向上一位
            }
                
            if(cur < 0)//全处理完了
                break;
            
            bool isTaken = false;
            for(int i = cur; i >= 0 ; i--)
            {
                if(taken[i] == nums[index[cur]])
                {
                    index[cur]++;//如果指向的数被前面拿着，指向下一个数
                    isTaken = true;
                    break;   
                }
            }
            if(isTaken)
                continue;
            
            //从这里开始，我们确定nums[index] 不在taken里面
            taken[cur] = nums[index[cur]];            
            ans[cur] = nums[index[cur]];
            cur++;//进入下一位。 考虑到我们拿到3个数，每选中一位可选的都会少一个数，所以我们不需要担心cur越界，因为已经被taken排除了这种情况。
            
            if(cur == nums.size())//但是还是需要保存答案的
                result.emplace_back(ans);
            else
                index[cur] = 0;
        }
        return result;
    }
};