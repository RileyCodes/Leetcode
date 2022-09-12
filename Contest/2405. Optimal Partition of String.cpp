class Solution {
public:
    int partitionString(string s) {
        
        int ans = 1;
        
        int lP = 0;
        int rP = 0;
        
        int counter[26]{0};
        //counter[s[`0] % 26 ] = 1;
        
        while(rP <= s.size())
        {
            int repCharAt = -1;
            for(int i = 0; i < 26;++i)
            {
                if(counter[i] >= 2)
                {
                    repCharAt = i;
                    break;
                }
            }
            if(repCharAt >= 0)
            {
                ++ans;
                lP = rP;
                for(int i = 0; i < 26;++i)
                {
                    counter[i] = i == repCharAt? 1 : 0;
                }
            }
            
            
            if(rP >= s.size())
               break;
            ++counter[s[rP] % 26];
            ++rP;
        }
        return ans;
    }
};