class Solution {
public:
    void reverseString(vector<char>& s) {
        int lP = 0;
        int rP = s.size() - 1;
        while(lP < rP)
        {
            swap(s[lP],s[rP]);
            ++lP;
            --rP;
        }
    }
};