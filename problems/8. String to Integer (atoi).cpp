class Solution {
public:
    int myAtoi(string s) {
        int num = 0;
        bool neg = false;
        int i = 0;
        
        while(s[i] == ' '){++i;}
        if(s[i] == '-')
        {
            neg = true;
            ++i;
        }
        else if(s[i] == '+')
            ++i;
        
        while(i < s.size())
        {
            if(s[i] < '0' || s[i] > '9')
            {
                                   
            }
            int digit = s[i] - 48;
            
            if(INT_MAX / 10 > num)
                num *= 10;
            else
            {               
                if(num > 214748364 || (i + 2) <= s.size())
                  digit = 9;
                
                if(neg)
                    digit = -min(8,digit);
                else
                    digit = min(7,digit);   
                
                num = (neg? -1 : 1) * 2147483640  + digit;
                return num;                     
            }
            
            num += digit;
            ++i;
        }
        
        return neg? -num : num;
    }
};