class Solution {
public:
    string removeStars(string s) {
        
        int totalStars = 0;
        for(int i = s.size() - 1; i >=0; --i)
        {
            if(s[i] == '*')
                ++totalStars;
        }
        int index = s.size() - (totalStars * 2);
        
        string result(index, 'x');
        int starCount = 0;
        for(int i = s.size() - 1; i >=0; --i)
        {
            if(s[i] != '*')
            {
                if(starCount > 0)
                    --starCount;
                else
                {
                    result[index - 1] = s[i];
                    --index;                    
                }
            }
            else
            {
                ++starCount;
            }
        }
        return result;
    }
};