class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int counter[26]{0};
        
        for(int i = 0; i < magazine.size(); ++i)
        {
            ++counter[magazine[i] % 26];
        }
        
        for(int i = 0 ; i < ransomNote.size(); ++i)
        {
            --counter[ransomNote[i] % 26];
            if(counter[ransomNote[i] % 26] < 0)
                return false;
        }
        return true;
    }
};