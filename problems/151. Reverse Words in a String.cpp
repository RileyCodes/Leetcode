class Solution {
public:

    //new today
    //yadot wen
    //today new]


    void swapRange(string& s, int lP, int rP)
    {
        while(lP < rP)
        {
            swap(s[lP++],s[rP--]);
        }
    }

    string reverseWords(string s) {

        
        swapRange(s, 0, s.size() - 1);

        int start = 0;
        for(int i = 0; i <= s.size(); ++i)
        {
            if(i == s.size() || s[i] == ' ')
            {
                swapRange(s, start, i - 1);
                start = i + 1;
            }
        }

        int slow = 0, fast = 0;
        bool begin = true;
        int n = s.size();
        while(fast < s.size())
        {
            if(s[fast] == ' ')
            {
                cout << "--" <<  slow << " " << fast << endl;
                if(fast == s.size() - 1)
                {
                    break;
                }
                if(begin)
                    begin = false;
                else
                    s[slow++] = s[fast++];
                while(fast < s.size() && s[fast] == ' ')
                {
                    cout << "n" << n << endl;
                    --n;
                    ++fast;
                }
                    
                continue;
            }
            begin = false;
            cout << slow << " " << fast << endl;
            s[slow] = s[fast];
            ++slow;
            ++fast;
        }
        cout << "n" << n << endl;
        cout << "slow" << s[slow - 1] << endl;
        if(s[slow - 1] == ' ')
            s.resize(slow - 1);
        else
            s.resize(slow);

        return s;
    }
};