class Solution {
    static const int max_ascii = 256;
    int charCountToFind[max_ascii] = {0};
    int matchedCharacters = 0;//2个词频表中有多少字符频率一致
    
    void UpdateWindowChrChange(int direction,char chr)
    {
        //方向可能是1，或者是-1，如果是1，说明我们失去了一个字符
        //否则，我们获得了一个字符
        
        //如果这个字符原本是匹配的，无论我们失去它，或者多拿到一个，我们匹配的字符少了一个。 因为频率必须完全一致。
        if(charCountToFind[(chr % max_ascii)] == 0)
            --matchedCharacters;
        
        charCountToFind[(chr % max_ascii)] += direction;

        //无论我们失去了还是获得了一个字符，在处理以后，如果我们的字符反而匹配了，那么我们匹配的字符多了一个
        if(charCountToFind[(chr % max_ascii)] == 0)
            ++matchedCharacters;
    }
    
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size())
            return false;
        
        int unique_character_count = 0;
        
        //构建需要匹配的词频表
        for(int i=0; i < s1.size();i++)
        {
            if(charCountToFind[(s1[i] % max_ascii)] == 0)
                ++unique_character_count;
            
            ++charCountToFind[(s1[i] % max_ascii)];
        }
        
        //初始化当前滑动窗口，我们发现的字符就--，失去的就++，这样只要频率为0就好了。
        for(int i=0; i < s1.size(); i++)
        {
            UpdateWindowChrChange(-1,s2[i]);
        }
        
        //启用一个靠左，宽度等于s1字符串的固定大小滑动窗口
        int slow = 0;
        int fast = s1.size() - 1;
        
        //开始向右滑动窗口
        while(fast < s2.size())
        {
            if(matchedCharacters == unique_character_count)
                return true;
            
            UpdateWindowChrChange(1,s2[slow]);
            
            ++slow;
            ++fast;
            
            UpdateWindowChrChange(-1,s2[fast]);
        }
        if(matchedCharacters == unique_character_count)
            return true;
        return false;
    }
};