class Solution {
public:


    bool isMatch(string s, string p) {

        if(p.size() == 0)
            return s.size() == 0;
        bool firstMatched = s.size() > 0 && (s[0] == p[0] || p[0] == '.');

        if(p.size() >= 2 && p[1] == '*')
        {
            return ((firstMatched &&  isMatch(s.substr(1),p)) || isMatch(s,p.substr(2)));
        }

        return firstMatched && isMatch(s.substr(1),p.substr(1));
    }
};