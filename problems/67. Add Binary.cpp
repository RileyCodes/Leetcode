class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() < b.size())
            swap(a,b);
        
        int diff = a.size() - b.size();
        for(int i = 0;i < diff; ++i)
        {
            b = "0" + b;
        }
        
        bool carry = false;
        
        int i = a.size() - 1;
        while(i >= 0)
        {
            if(carry)
            {
                if(a[i] == '1')
                {
                    a[i] = '0';
                }
                else
                {
                    a[i] = '1';
                    carry = false;
                }
            }
            if(a[i] == '1' && b[i] == '1')
            {
                a[i] = '0';
                carry = true;
            }
            else if(a[i] == '0' && b[i] == '1')
            {
                a[i] = '1';
            }              
            --i;
        }
        if(carry)
        {
            a = "1" + a;
        }
        return a;
    }
};