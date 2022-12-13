class Solution {
public:
    unordered_map<long long ,bool> cache;

    bool _isMatch(const string& s, const string& p,int sIndex, int pIndex)
    {
        long long key = sIndex;
        key <<= 32; key |= pIndex;

        if(cache.count(key) > 0)
            return cache[key];

        if(pIndex == p.size())
        {
            auto res = s.size() == sIndex;
            cache[key] = res;
            return res;
        }
            

        bool matched = s.size() > sIndex && (s[sIndex] == p[pIndex] || p[pIndex] == '?' || p[pIndex] == '*');

        if(p[pIndex] == '*')
        {
            auto res = (matched && _isMatch(s, p,sIndex + 1,pIndex)) || _isMatch(s,p, sIndex, pIndex + 1);
            cache[key] = res;            
            return res;
        }
            
        
        auto res = matched && _isMatch(s,p, sIndex + 1,pIndex + 1);
        cache[key] = res;            
        return res;            
    }

    bool isMatch(string s, string p) {
        return _isMatch(s,p,0,0);
    }
};  