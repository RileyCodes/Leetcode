class Solution {
public:
    bool isPalindrome(int x) {
        //3 / 2 = 1.5 = 1
        //4 / 2 = 2
        //5 / 2 = 2.5 = 2
        //1001 / 10 = 100
        // 1001 % 10 = 1
        
        int num[32]{0};
        int count = 0;
        if(x < 0)
            return false;
        
        while(x > 0)
        {
            num[count++] =x % 10;
            x = x / 10;
        }
        
        int mid = count / 2;
        int j = count - 1;
        for(int i = 0 ; i < mid; ++i)
        {
            if(num[i] != num[j])
                return false;
            j--;
        }
        
        return true;
    }
};