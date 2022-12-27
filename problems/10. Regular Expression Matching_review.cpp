class Solution {
public:

    unordered_map<short, bool> m;

    bool recur(const string&s, const string& p, int pIndex, int sIndex)
    {
        short hash = 0;
        hash |= pIndex; hash <<= 8; hash |= sIndex;
        if(m.count(hash))
            return m[hash];
        if(pIndex >= p.size() && sIndex >= s.size())
        {
            m[hash] = true;
            return true;
        }
        

        bool isMatched = sIndex < s.size() && (p[pIndex] == '.' || s[sIndex] == p[pIndex]);

        //Wildcard exists
        if(pIndex + 1 < p.size() && p[pIndex + 1] == '*')
        {
            auto res = (isMatched && recur(s,p,pIndex + 2, sIndex + 1)) || 
            (isMatched && recur(s,p,pIndex, sIndex + 1)) ||
            recur(s,p,pIndex + 2, sIndex);
            m[hash] = res;
            return res;
        }
        else
        {
            auto res = isMatched && recur(s,p,pIndex + 1, sIndex + 1);
            m[hash] = res;
            return res;
        }
            

        //???
        return false;
    }

    bool isMatch(string s, string p) {
        return recur(s,p,0,0);
    }
};