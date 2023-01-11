class Solution {
public:
    bool checkIfPangram(string sentence) {
        int counter[26]{0};
        for(auto&& chr : sentence)
            ++counter[chr % 26];
        
        for(int i = 0; i < 26 ; ++i)
        {
            if(counter[i] == 0)
                return false;
        }
        return true;
    }
};