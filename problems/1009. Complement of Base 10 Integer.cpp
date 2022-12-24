class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0)
            return 1;
        
        int mask = -1;
        int cnt = 0;
        int tmp = n;
        
        while(tmp > 0)
        {
            tmp /= 2;
            ++cnt;
        }
        
            
        mask = (unsigned int)mask << cnt;
        
        n |= mask;
        
        
        return ~n;
    }
};