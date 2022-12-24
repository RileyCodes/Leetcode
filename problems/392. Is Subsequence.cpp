class Solution {
public:
    
    int FindIndex(const string& t, const char chr, int curIndex)
    {
        while(curIndex < t.size())
        {
            if(t[curIndex] == chr)
                return curIndex + 1;
            ++curIndex;
        }        
        return -1;
    }
    
    
    bool isSubsequence(string s, string t) {
        
        int index = 0;
        for(auto&& chr : s)
        {
            index = FindIndex(t,chr,index);
            if(index == -1)
                return false;
        }
        return true;
    }
};