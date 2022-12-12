class Solution {
public:
    unordered_map<long long,int> m;
    int numDecodings(const string& s, int index, int len)
    {
        long long key = 0;
        key |= index;
        key <<= 32;
        key |= len;
        if(m.count(key) != 0)
            return m[key];

        if(s[index] == '0')
        {
            m[key] = 0;
            return 0;
        }
    
        
        int cnt = 0;
        for(int i = 0; i < len; ++i)
        {
            cnt += s[index + i] - '0';
            cnt *= 10;
        }
        cnt /= 10;

        if(cnt > 26)
        {
            m[key] = 0;
            return 0;
        }
        if(index == 0)
        {
            m[key] = 1;
            return 1;
        }
        int cnt1 = numDecodings(s,index - 1,1);
        int cnt2 = 0;
        if(index - 2 >= 0)
        cnt2 = numDecodings(s,index - 2,2);

        m[key] = cnt1 + cnt2;
        return cnt1 + cnt2;        
    }


    int numDecodings(string s) 
    {
        int cnt1 = numDecodings(s, s.size() - 1, 1);
        int cnt2 = 0;
        if(s.size() > 1)
            cnt2 = numDecodings(s, s.size() - 2, 2);
        return cnt1 + cnt2;
    }
};