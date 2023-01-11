class Solution {
public:

    void count(string&s, int& res)
    {
        static set<char> st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');

        st.insert('A');
        st.insert('E');
        st.insert('I');
        st.insert('O');
        st.insert('U');

        for(auto&& chr : s)
        {
            if(!st.count(chr))
                continue;
            ++res;
        }
            
    }

    bool halvesAreAlike(string s) {
        string s1, s2;
        s1 = s.substr(0, s.size() / 2);
        s2 = s.substr((s.size() / 2) );

        int res1 = 0, res2 = 0;
        count(s1, res1);
        count(s2, res2);

        
        return res1 == res2;
    }
};