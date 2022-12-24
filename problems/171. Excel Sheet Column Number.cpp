class Solution {
public:
    
    int colToNum(char col)
    {
        return col - 'A' + 1;
    }
    
    int pow(int num,int exp)
    {
        int d = 1;
        for(int i = 0 ; i < exp; ++i)
            d *= num;
        return d;
    }
    
    int titleToNumber(string columnTitle) {
        
        int count = 0;
        int ans = 0;
        for(int i = columnTitle.size() - 1; i >=0;--i)
        {
            ans += colToNum(columnTitle[i]) * pow(26,count++);
        }
        return ans;
    }
};