class Solution {
public:
    int strStr(string haystack, string needle) {
        const long long Q = 1658598167;
        long long hash = 0;
        int lP = 0, rP = 0;
        long long digit = 255;
        int wndWidth = needle.size();
        long long needleHash = 0;
        for(auto&& chr : needle)
            needleHash = ((needleHash * digit) + chr) % Q;
        

        long long RL = 1;
        for(int i = 0 ;i < needle.size() - 1;++i)
        {
            RL = digit * RL;
            RL %= Q;
        }

        while(rP < haystack.size())
        {
            while(rP < haystack.size() && rP - lP < wndWidth)
            {
                hash = (((hash * digit) % Q) + haystack[rP]) % Q;
                ++rP;
            }

            if(hash == needleHash)
                return lP;
            
            hash = (hash - (haystack[lP] * RL) % Q + Q) % Q;
            ++lP;
        }

        return -1;
    }
};