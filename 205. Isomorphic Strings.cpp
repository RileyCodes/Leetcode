class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        const int max_ascii = 256;
        vector<int> map(max_ascii);
        vector<bool> mapped_from(max_ascii);
        vector<bool> mapped_to(max_ascii);

        for(int i = 0; i < s.size();++i)
        {
            if(mapped_from[s[i] % max_ascii])
            {
                s[i] = map[s[i] % max_ascii];
            }
            else
            {
                if(mapped_to[t[i] % max_ascii])
                    return false;
                mapped_from[s[i] % max_ascii] = true;
                mapped_to[t[i] % max_ascii] = true;                    
                map[s[i] % max_ascii] = t[i];
                s[i] =  map[s[i] % max_ascii];
            }           
        }
        
        cout << s << endl;
        cout << t << endl;
        
        return s == t;
    }
};