class Solution {
public:
    unordered_map<int, int> m;
    bool isVaild()
    {
        for(auto&& kv : m)
        {
            if(kv.second < 0)
                return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        for(int i = 0; i < t.size(); ++i)
            --m[t[i]];

        int lP = 0, rP = 0;
        int minWnd = INT_MAX;
        int minlP, minrP;

        while(rP < s.size())
        {
            while(rP < s.size() && !isVaild())
            { 
                ++m[s[rP]];
                ++rP;
            }
            while(isVaild())
            {
                if(rP - lP < minWnd)
                {
                    minWnd = rP - lP;
                    minlP = lP;
                    minrP = rP;
                }
                --m[s[lP]];
                ++lP;
            }
        }

        if(minWnd == INT_MAX)
            return "";
        return s.substr(minlP, minrP - minlP);
    }
};