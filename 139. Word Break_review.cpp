class Solution {
public:

    unordered_map<int, bool>cache;

    bool wordBreak(const string& s, const set<string>& sWords, const set<int>& sNums,int index) 
    {
        if(cache.count(index) > 0)
            return cache[index];

        for(auto len : sNums)
        {
            if(s.size() < index + len)
                continue;


            string substr = s.substr(index,len);
            if(sWords.count(substr) == 0)
                continue;


            if(index + len == s.size())
            {
                cache[index] = true;
                return true;
            }
                

            if(wordBreak(s, sWords,sNums, index + len))
            {
                cache[index] = true;
                return true;
            }   
        }

        cache[index] = false;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> sWords;
        set<int> sNums;
        for(auto word : wordDict)
        {
            sWords.emplace(word);
            sNums.emplace(word.size());
        }

        return wordBreak(s, sWords, sNums, 0);
    }
};