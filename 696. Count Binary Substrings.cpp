class Solution {
public:
    
    //111000 -> 1100 -> 10, we have 3 substrings
    //00001111-> 000111 -> 0011 -> 01  we have 4 substrings
    //000011111 - invaild, we can still only take this as 0000111 so we have 4 substrings
    //000011110 we take this as  00001111 and 10, so 5 substrings.
    
    
    
    int countBinarySubstrings(string s) {
        vector<int> groupCount;
        groupCount.emplace_back(1);
        int index = 0;
        for(int i = 1; i < s.size(); ++i)
        {
            if(s[i] != s[i - 1])
            {
                groupCount.emplace_back(1);
                ++index;
            }
            else
            {
                ++groupCount[index];
            }
        }
        
        int cnt = 0;
        
        for(int i = 1; i < groupCount.size(); ++i)
        {
            cnt += min(groupCount[i],groupCount[i - 1]);
        }
        
        return cnt;
    }
};