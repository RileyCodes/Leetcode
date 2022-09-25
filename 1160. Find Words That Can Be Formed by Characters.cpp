class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int charCounter[26]{0};
        int cnt = 0;
        for(int i = 0; i < chars.size(); ++i)
        {
            ++charCounter[chars[i] % 26];
        }
        
        for(int i = 0; i < words.size(); ++i)
        {
            int tmpCounter[26];
            for(int k = 0; k < 26; ++k)
            {
                tmpCounter[k] = charCounter[k];
            }
            
            bool good = true;

            for(int j = 0; j < words[i].size();++j)
            {
                --tmpCounter[words[i][j] % 26];
                if(tmpCounter[words[i][j] % 26] < 0)
                {
                    good = false;
                    break;
                }
            }
            
            if(good)
                cnt += words[i].size();
        }
        return cnt;
    }
};