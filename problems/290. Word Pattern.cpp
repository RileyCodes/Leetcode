class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> mapper(26);
        unordered_map<string,char> mapped_to;
        
        int startIndex = 0;
        int end = 0;
        bool found_word = false;
        int word_count = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == ' ')
            {
                end  = i - 1;
                found_word = true;
            }
            else if(i + 1 == s.size())
            {
                end  = i;
                found_word = true;
            }
            if(found_word)
            {
                
                string word = s.substr(startIndex,end - startIndex + 1);
                char pat = pattern[word_count];
                //cout << word << " " << pat << endl;
                if(mapper[pat % 26] != "")
                {
                    if(mapper[pat % 26] != word)
                        return false;
                }
                else
                {
                    if(mapped_to.count(word) != 0)
                        return false;
                    mapper[pat % 26] =  word;
                    mapped_to[word] = pat;
                }
                
                startIndex = end + 2;
                found_word = false;
                
                
                ++word_count;
            }
        }
        return word_count == pattern.size();
    }
};