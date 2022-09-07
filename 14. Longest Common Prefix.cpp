class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int count = 0;
        while(1)
        {
            char lastChar = strs[0][count];
            for(int i = 0; i < strs.size(); ++i)
            {
                if(strs[i].size() <= count || strs[i][count] != lastChar)
                {
                    return strs[0].substr(0,count);
                }
            }
            ++count;
        }
        return strs[0].substr(0,count);
    }
};