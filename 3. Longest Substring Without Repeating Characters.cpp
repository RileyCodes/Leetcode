class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256] = {0};
        int slow = 0, fast = 0;
        int maxFound = 0;
        while(fast < s.size())
        {
            char fastChr = s[fast];
            if(hash[fastChr] != 0)
            {
                char slowChr = s[slow];
                --hash[slowChr];
                ++slow;
                continue;
            }
            
            const int localMax = fast - slow + 1;
            maxFound = maxFound < localMax ? localMax : maxFound;
            
            ++hash[fastChr];
            ++fast;
        }
        return maxFound;
    }
};