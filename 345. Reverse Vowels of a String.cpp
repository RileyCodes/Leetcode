class Solution {
public:
    string reverseVowels(string s) {
        bool vowels[256]{0};
        vowels['a' % 256] = true;
        vowels['e' % 256] = true;
        vowels['i' % 256] = true;
        vowels['o' % 256] = true;
        vowels['u' % 256] = true;
        vowels['A' % 256] = true;
        vowels['E' % 256] = true;
        vowels['I' % 256] = true;
        vowels['O' % 256] = true;
        vowels['U' % 256] = true;        
        
        
        int lP = 0;
        int rP = s.size() - 1;
        
        while(lP < rP)
        {
            if(vowels[s[lP] % 256])
            {
                if(vowels[s[rP] % 256])
                {
                    swap(s[lP++],s[rP--]);
                }
                else
                    --rP;
            }
            else
                ++lP;
        }
        return s;
    }
};