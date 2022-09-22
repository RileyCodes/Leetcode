class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num2.size() > num1.size())
            swap(num2,num1);
        
        int diff = num1.size() - num2.size();
        for(int i = 0; i < diff;++i)
        {
            num2 = "0" + num2;
        }
        
        string ans;
        bool carry = false;
        for(int i = num1.size() - 1; i >= 0; --i)
        {
            
            int num = (num1[i] - 48) + (num2[i] - 48);
            if(carry)
            {
                num += 1;
                carry = false;
            }
                
            if(num >= 10)
                carry = true;
            
            int digit = ((num % 10) + 48);
            
            ans = (char)digit + ans;
        }
        
        
        if(carry)
        {
            ans = "1" + ans;
        }
        
        return ans;
    }
};