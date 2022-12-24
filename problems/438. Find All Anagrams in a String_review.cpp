class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int s_count[26]{0};
        for(auto&& chr : p)
            --s_count[chr - 'a'];
        int lP = 0, rP = 0;
        int matchNeeded = p.size();
        vector<int> ans;
        while(rP < s.size())
        {

            while(rP - lP < p.size() && rP < s.size())
            {
                
                int charIndex = s[rP] - 'a';
                ++s_count[charIndex];
                if(s_count[charIndex] <= 0)
                    --matchNeeded;

                ++rP;
            }
            cout << matchNeeded << endl;
            if(matchNeeded == 0)
                ans.emplace_back(lP);
            
            int charIndex = s[lP] - 'a';
            --s_count[charIndex];
            if(s_count[charIndex] + 1 <= 0)
                ++matchNeeded;
            ++lP;   
        }
        return ans;
    }
};