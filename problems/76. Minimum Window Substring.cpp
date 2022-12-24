class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> needed, window;
        //build needed character table
        for(auto&& chr : t)
        {
            if(needed.count(chr) == 0)
                needed[chr] = 1;
            else
                ++needed[chr];
        }

        int lP = 0, rP = 0;
        int vaild = t.size();
        int minVaild = INT_MAX;
        int minBegin = 0, minSize = 0;

        int vaildCnt = 0;
        while(rP <= s.size())
        {
            //In case window is smaller than t, which is not possibile to include t
            while(rP < s.size() && rP - lP < t.size())
            {
                if(window.count(s[rP]) == 0)
                    window[s[rP]] = 1;
                else
                    ++window[s[rP]];
                //cout << s[rP] << " wnd " << window[s[rP]]<< endl;

                if(needed.count(s[rP]) && window[s[rP]] <= needed[s[rP]])
                    ++vaildCnt;                
                ++rP;
            }

            //In case the window is vaild, we try to reduce window from left side.
            while(vaildCnt == vaild && rP - lP >= t.size())
            {
                //cout << "reduce" << endl;
                //if we are moving away from a character, we want to make sure it wont make the window invaild.
                if(needed.count(s[lP]) && (window[s[lP]] - 1) < needed[s[lP]])
                    break;                
                --window[s[lP]];
                ++lP;
            }
            //cout << vaildCnt << endl;
            
            //now that we got a localminium, we can try to compare and store.
            if(vaildCnt == vaild)
            {
                 //cout << "foundVaild" << endl;
                if(minVaild > rP - lP)
                {
                    minVaild = rP - lP;
                    minBegin = lP;
                    minSize = rP - lP;
                }
            }
            //try to expand and find new local solution

            
            if(window.count(s[rP]) == 0)
                window[s[rP]] = 1;
            else
                ++window[s[rP]];
            //cout << s[rP] << " wnd " << window[s[rP]]<< endl;
            if(needed.count(s[rP]) && window[s[rP]] <= needed[s[rP]])
                ++vaildCnt;       
            ++rP;  
        }
        if(minVaild == INT_MAX)
            return "";
        return s.substr(minBegin, minSize);
    }
};
