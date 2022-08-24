class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        //大小等于字符串字符数量的状态数组
        vector<bool> state(s.size() + 1);
        state[0] = true;//其中初始条件0始终是true
        
        //我们从0开始一直处理到最后一个，路上遇到true，就进行状态转移
        for(int i = 0; i < state.size(); ++i)
        {
            if(state[i])
            {
                for(int j = 0; j < wordDict.size(); j++)
                {
                    if(i + wordDict[j].size() >= state.size())//如果越界了，就不是一个有效的尝试
                        continue;
                    
                    string cmp = s.substr(i,wordDict[j].size());
                    if(cmp == wordDict[j])
                        state[i + wordDict[j].size()] = true;       
                }
            }
        }
        
        return state[state.size() - 1];
    }
};
