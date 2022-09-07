class Solution {
public:
    bool isPalindrome(string s) {
        
        string test;
        for(int i =0 ; i < s.size(); ++i)
        {
            if(s[i] >= 'A' && s[i] <= 'Z')
                test += s[i] - ('A' - 'a');
            else if(s[i] >= 'a' && s[i] <= 'z' || (s[i] >= '0' && s[i] <= '9'))
                test += s[i];
        }
        
        //bool isEven = test.size() % 2 == 0;
        
        int checkCount = test.size() / 2;
        
        int i = 0,j = test.size() - 1;
        while(i < checkCount)
        {
            if(test[i] != test[j])
                return false;
            ++i;
            --j;
        }
        
        return true;
    }
};