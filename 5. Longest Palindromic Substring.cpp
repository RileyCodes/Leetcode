class Solution {
public:
    /*
    直接对每个节点使用中心扩散法
    */
    string longestPalindrome(string s) {
        int maxIndex = -1;//找到的最大回文子串的索引位置
        int maxRad = -1;//找到的最大回文子串的半径
        int addtLen = 0;//额外长度（由于abba的bb这种情况）
        
        //从左到右扫描字符串
        for(int i = 0; i < s.size(); ++i)
        {
            //左右指针一开始指着i
            int lP = i;
            int rP = i;    
            int localRad = -1;
            int localAddtLen = 0;
            while(rP + 1 < s.size() && s[rP] == s[rP + 1])
            {
                //如果在一开始的时候，i右边也有东西，而且和i和i+1一样
                //这说明我们可能遇到了abba这种情况，当然也可能是abbc
                //这种时候，我们需要向右搜索，改变右指针的位置，因为除了abba 还可能会有abbbbbc abbba这类情况
                //我们的左右指针必须在一轮循环以后，对于abbba这种情况，左右分别指向左右的a。
                ++rP;
                ++localAddtLen;
            }
            
            //左指针向左，右指针向右，没越界就继续循环。 
            while(lP >= 0 && rP < s.size())
            {
                //每轮循环，如果左右不一致，直接跳出结束对本中心的检查。
                if(s[lP] != s[rP])
                    break;
                ++localRad;
                if((localRad * 2 + 1) + localAddtLen > (maxRad * 2) + 1 + addtLen)//如果我们发现了更长的回文子串，更新最大半径和为止为新的。
                {
                    maxRad = localRad;
                    maxIndex = lP;//lP始终指向子串的最左侧。
                    addtLen = localAddtLen;
                }
                --lP;
                ++rP;
            }            
        }
            
        //根据位置和半径返回子串，之所以是maxRad * 2 + 1，看看这几种情况
        //aba : 半径是1， 2 + 1 = 3
        //abxba，半径是2, 2 * 2 + 1 = 5
        //abxxba，半径是2, 2 * 2 + 1 = 5，但是我们实际长度是6。 这说明了我们对偶数对称需要另外处理

        return s.substr(maxIndex,maxRad * 2 + 1 + addtLen);
    }
};