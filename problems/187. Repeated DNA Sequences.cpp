class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;

        if(s.size() <= 10)
            return ans;        

        unordered_map<char,int> m;
        m['A'] = 0;
        m['C'] = 1;
        m['G'] = 2;
        m['T'] = 3;

        int wndHash = 0;
        const int digit = 4;

        int lP = 0, rP = 0;
        set<int> _set;
        set<string> sAns;

        while(rP < s.size())
        {
            while(rP < s.size() && rP - lP < 10)
            {
                wndHash = (digit * wndHash) + m[s[rP]];
                ++rP;
            }
            if(!_set.count(wndHash))
                _set.insert(wndHash);
            else
                sAns.insert(s.substr(lP, rP - lP));

            wndHash = wndHash - (m[s[lP]] * pow(digit, 9));
            ++lP;
        }

        ans.assign(sAns.begin(), sAns.end());
        return ans;
    }
};