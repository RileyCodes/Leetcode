class Solution {
public:
    /*
·   这道题要求给出一个字符串，如abc，找出另一个字符串里面，所有以abc的各种组合变化构成的子字符串。
    如 s = "cbaebabacd", p = "abc" 输出就是[0,6]
    因为在[0]开头的的cba和在[6]开头的bac都是abc的组合变化。
    
    还记得我们以前遇到过类似的一个题目，我们用滑动窗口+词频表解决了这个问题。 
    首先用一个哈希表记录每个字符应该出现几次，如 a = 1 b = 1 c = 1
    然后我们用滑动窗口维护当前窗口内每个字符的数量。 如果也满足a = 1 b = 1 c = 1 就说明我们找到了一个组合。
    */
    vector<int> findAnagrams(string s, string p) {
        vector<int> table(26);//建立词频表
        vector<int> result;//结果数组
        
        if(s.size() < p.size())
            return result;
        
        int matched = 0;
        int needToMatch = 0;
        for(int i = 0; i < p.size();++i)
        {
            if(table[p[i] - 'a'] == 0)//每当有一个新的字母需要匹配，我们增加需要匹配的字母计数，这是避免出现aa这种重复字母的情况。 
                ++needToMatch;
            ++table[p[i] - 'a'];//把我们需要的词频记录下来。
        }
        
        int lP = 0;
        for(int rP = 0; rP < s.size(); ++rP)//滑动窗口走到最右边才算完
        {
            --table[s[rP] - 'a'];//把当前右指针新指向的东西计入频率。
            if(table[s[rP] - 'a'] == 0)//如果我们这次纳入的字母导致频率一致了，那么我们匹配的字母就多了一个
                ++matched;       //如果这次纳入的不一致，就不变化，因为我们并没有因此多匹配了一个字符，也没有因此少匹配了一个字符（滑动窗口左侧指针离开的时候，才会出现失去原本匹配的字符）
            
            //在一开始的时候，滑动窗口宽度还没达到目标宽度，这种情况下左指针不动 也不需要考虑是否有答案
            if((rP - lP) + 1 >= p.size())
            {                   
                if(matched == needToMatch)
                    result.emplace_back(lP);//匹配数量一致，添加答案。                
                
                ++table[s[lP] - 'a'];//失去的东西的频率++
                if(table[s[lP] - 'a'] == 1)//如果我们这次纳入的字母导致频率不一致了，那么就要看以前是是不是匹配的
                //如果以前匹配，现在不一致了，我们匹配的字母就少了一个。 而如果原本就不匹配，那么我们匹配数量就没有变。
                //以前匹配，说明原本是0，现在只能是1
                    --matched;
                ++lP;
            }
        }
        
        return result;
    }
};