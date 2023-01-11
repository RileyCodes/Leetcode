class Solution {
public:
    string makeGood(string s) {
        int i = 0;
        while(1)
        {
            if(s.size() == 0)
                break;
            if(i >= s.size() - 1)
                break;
            
            if((s[i] >= 'a' && s[i + 1] <= 'Z' && (s[i] - (97 - 65)) == s[i + 1]) ||
            (s[i] <= 'Z' && s[i + 1] >= 'a' &&  (s[i] + (97 - 65)) == s[i + 1]))
            {
                string tmp;
                tmp = s.substr(0 , i);
                if(i + 2 < s.size())
                    tmp += s.substr(i + 2);
                s = tmp;
                cout << s << endl;
                i = 0;
                continue;
            }
            ++i;
        }
    
        return s;
    }
};