class Solution {
public:
    unordered_map<int,bool> m;

    bool isMatch(string& s, int sIndex, string&p, int pIndex)
    {
        int key = sIndex; key <<= 16; key |= pIndex;
        if(m.count(key))
            return m[key];
        
        
        if(pIndex >= p.size())
        {
            m[key] = sIndex >= s.size();
            return sIndex >= s.size();
        }
            

        bool matched = sIndex < s.size() && (s[sIndex] == p[pIndex] || p[pIndex] == '?');

        if(p[pIndex] != '*')
        {
            bool res = matched && isMatch(s, sIndex + 1, p, pIndex + 1);
            m[key] = res;
            return res;
        }
            
        bool res = isMatch(s, sIndex, p, pIndex + 1) || (sIndex < s.size() && isMatch(s, sIndex + 1, p, pIndex));
        m[key] = res;
        return res;
    }

    bool isMatch(string s, string p) {

        return isMatch(s, 0, p, 0);
    }
};