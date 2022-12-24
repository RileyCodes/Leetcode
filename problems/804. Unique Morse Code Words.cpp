class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string m[26]{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> s;
        int count = 0;
        for(int i = 0; i < words.size(); ++i)
        {
            string code;
            for(int j = 0; j < words[i].size(); ++j)
            {
                code += m[words[i][j] - 'a'];
            }
            if(s.count(code) == 0)
            {
                s.insert(code);
                ++count;
            }
        }
        
        return count;
    }
};