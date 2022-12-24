class Solution {
public:
    int similarPairs(vector<string>& words) {
        int pairCnt = 0;
        


        for(int i = 0; i < words.size(); ++i)
        {
            set<char> chars;
            for(auto word : words[i])
            {
                chars.insert(word);
            }
            
            for(int j = i + 1; j < words.size(); ++j)
            {
                bool allExists = true;
                set<char> charsJ;
                for(auto word : words[j])
                {
                    charsJ.insert(word);                
                }
                for(int z = 0; z < 26; ++z)
                {
                    if(chars != charsJ)
                    {
                        allExists = false;
                    }
                }

                
                if(allExists)
                {
                    ++pairCnt;
                }
            }
        }
        return pairCnt;
    }
};