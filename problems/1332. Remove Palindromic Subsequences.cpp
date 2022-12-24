class Solution {
public:
    //ab
    //abaa
    //abba
    //baabb
    int removePalindromeSub(string s) {
        bool isPerfectPalindrome = true;
    
        int lP = 0, rP = s.size() - 1;
        while(lP <= rP)
        {
            if(s[lP] != s[rP])
            {
                isPerfectPalindrome = false;
                break;
            }
            ++lP;
            --rP;
        }
        
        return isPerfectPalindrome? 1 : 2;
    }
};