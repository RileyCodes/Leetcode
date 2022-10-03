class Solution {
public:
    
    //abcde -> ebcda -> edcba
    
    string reverseStr(string s, int k) {
        
        for(int i = 0; i < s.size(); i += (2 * k))
        {
            int lP = i;
            int rP = min((i + k - 1), (int)(s.size() - 1));
            while(lP < rP)
            {
                swap(s[lP],s[rP]);
                ++lP;
                --rP;
            }      
        }
        return s;      
    }
};