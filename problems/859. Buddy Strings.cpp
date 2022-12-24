class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int goalCounter[26]{0}, sCounter[26]{0};
        
        int mismatchCount = 0; // we can only swap once, can solve only when mismatch == 2
    
        
        for(int i = 0; i < s.size(); ++i)
        {
            ++sCounter[s[i] % 26];
            
            if(s[i] != goal[i])
                ++mismatchCount;
        }
        for(int i = 0 ; i < goal.size(); ++i)
        {
            ++goalCounter[goal[i] % 26];
        }
        
        bool isSame = true;
        bool hasTwoSameChar = false;
        for(int i = 0; i < 26; ++i)
        {
            if(sCounter[i] != goalCounter[i])
                isSame = false;
            
            if(sCounter[i] >= 2)
                hasTwoSameChar = true;
        }
        
        
   
        if(!isSame)//Some char in s had diff amount than,goal for example:aba,ab, no way to fix this by swap.
            return false;
        
        //but if we can fix by swap ,can we break it by swap? swap is always required.
        
        //ab swap = ba...
        //aa swap = aa
        //if we are not at goal and its same, then its fine
        //but if we are at goal,ex : aab,aab, the only way to fix this is to swap a and a 
        //so we need to check if we got two same char.
        
        return isSame && (s != goal || hasTwoSameChar) && (mismatchCount == 2 || mismatchCount == 0);
    }
};