class Solution {
public:
    string smallestSubsequence(string s) {
       int count[26]{0};
       int used[26]{0};

       for(auto&& chr : s)
            ++count[chr - 'a'];
        stack<char> st;
        for(int i = 0; i < s.size(); ++i)
        {
            char curChr = s[i] - 'a';
            if(used[curChr] != 0)
            {
                --count[curChr];
                continue;
            }
            if(st.empty())
            {
                ++used[curChr];
                st.push(curChr);
                continue;
            }
            while(!st.empty() && st.top() > curChr && count[st.top()] > 1)
            {
                --used[st.top()];
                --count[st.top()];
                st.pop();
            }
            st.push(curChr);
            ++used[curChr];                     
        }
        string ans;
        while(!st.empty())
        {
            char chr = (st.top() + 'a') ;
            ans += chr;
            st.pop();
        }
        std::reverse(ans.begin(),ans.end());
        return ans;
    }
};