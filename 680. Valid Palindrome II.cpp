class Solution {
public:
    //"ececcec"
    //"ceccec" - ok
    //"ececce" - fail
    
    bool recur(string& s, int lP,int rP,bool oneChance)
    {
        while(lP <= rP)        
        {
            if(s[lP] != s[rP])
            {
                if(!oneChance)
                    return false;
                if(recur(s, lP + 1,rP,false))
                    return true;
                else if(recur(s, lP,rP - 1,false))
                    return true;
                else
                    return false;
            }
            ++lP;
            --rP;            
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        
        int lP = 0, rP = s.size() - 1;
        return recur(s, lP,rP,true);
    }
};