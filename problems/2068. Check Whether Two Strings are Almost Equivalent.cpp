class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int count1[26]{0};
        int count2[26]{0};

        for(auto&& chr : word1)
            ++count1[chr % 26];
        for(auto&& chr : word2)
            ++count2[chr % 26];
        for(int i = 0; i < 26; ++i)
        {
            if(abs(count1[i] - count2[i]) > 3)
                return false;
        }
        return true;
    }
};