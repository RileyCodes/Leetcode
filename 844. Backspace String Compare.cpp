class Solution {
public:
    
    /*
        这道题要求计算考虑到退格以后，两个字符串是否相等。
        直接2个指针从右到左一个个判定，如果遇到退格，就记录下退格的次数
        在退格次数>= 0的情况下，忽略非退格字母，退格次数--
        在退格次数==0的情况下 比较2个指针的字符是否一样。
        如果已经走到了字符串边界，那么边界本身是一个特殊字母。
    */
    bool backspaceCompare(string s, string t) {
        int pS = s.size() - 1;
        int pT = t.size() - 1;
        int sCounter = 0;
        int tCounter = 0;
        while(pS >= 0 || pT >= 0)
        {
            if(pS >= 0 && s[pS] == '#')
            {
                ++sCounter;
                --pS;
            }
            else if(pT >= 0 && t[pT] == '#')
            {
                ++tCounter;            
                --pT;
            }
            else//双方都走到了非退格字母上，但是也有可能其中一个到头了
            {
                if(sCounter > 0)
                {
                    --pS;
                    --sCounter;
                }
                    
                else if(tCounter > 0)
                {
                    --pT;
                    --tCounter;
                }
                    
                else//该退格的都退格了，此时有两种可能性，一种是指针指着不会被退格的字母，还一种可能性是指针已经被退格到负数去了。
                {
                    if((pS < 0 && pT >= 0) || (pT < 0 && pS >= 0))//如果出现了其中一方被退格到负数了，另一方却有字母，那就说明不相等
                        return false;
                    if((pS >= 0 && pT >=0) && s[pS] != t[pT])//字母不一样，不相等。
                        return false;
                    //比较完了，左移。
                    --pS;
                    --pT;
                }
                    
            }  
        }
        
        return true;//默认满足。我们的逻辑把不满足的情况挑了出来。
    }
};
