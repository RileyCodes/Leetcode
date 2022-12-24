class Solution {
public:
    int hammingWeight(uint32_t n) {
        /*
        观察：
        1 = 10
        0 = 01
        10 & 
        01 = 00，一共有一个1
        
        1111 下一位是10000
        01111 &
        10000 = 0 一共有一个1
        
        1110 上一位是1100
        1100 &
        1110 = 1100
        1100 &
        1011 = 1000
        0111 &
        1000 = 0 
        由此可见，只要一直和上一位做 & 然后计数，就能知道整数有多少个二进制1在里面了
        
        */
        
        int counter = 0;
        while(n != 0)
        {
            n = n & (n - 1);
            counter++;
        }
        return counter;
    }
};