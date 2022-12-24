class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int count = 0;
        bool isFoundFirstAlpha = false;
        for(int i = s.size() - 1;i >=0 ; --i)
        {
            if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
            {
                isFoundFirstAlpha = true;
                ++count;
            }
            else if(isFoundFirstAlpha)
            {
                return count;
            }
        }
        
        return count;
    }
};