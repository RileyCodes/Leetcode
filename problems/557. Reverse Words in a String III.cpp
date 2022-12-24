class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        for(int i=0; i < s.size(); i++)
        {
            if(s[i] == ' ')
            {
                int lP = start;
                int rP = i - 1;
                while(lP < rP)
                {
                    swap(s[lP],s[rP]);
                    ++lP;
                    --rP;
                }
                start = i + 1;
            }
        }
        
        int lP = start;
        int rP = s.size() - 1;
        while(lP < rP)
        {
            swap(s[lP],s[rP]);
            ++lP;
            --rP;
        }
        return s;
    }
};