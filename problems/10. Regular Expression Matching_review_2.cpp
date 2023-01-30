class Solution {
public:

    unordered_map<int,bool> cache;

    bool recur(const string& s, int sIndex, const string& p, int pIndex)
    {
        int key = sIndex; key <<= 16; key |= pIndex;
        if(cache.count(key))
            return cache[key];

        if(sIndex >= s.size() && pIndex >= p.size())
        {
            cache[key] = true;
            return true;
        }
            

        bool isMatched = sIndex < s.size() && (s[sIndex] == p[pIndex] || p[pIndex] == '.'); 
        if(pIndex + 1 >= p.size()  || p[pIndex + 1] != '*')
        {
            cache[key] =  isMatched && recur(s, sIndex + 1, p, pIndex + 1);
            return cache[key];
        }
        cache[key] = (isMatched && recur(s, sIndex + 1, p, pIndex)) || recur(s, sIndex, p, pIndex + 2);
        return cache[key];
    }

    bool isMatch(string s, string p) {
        return recur(s, 0 ,p, 0);
    }
};