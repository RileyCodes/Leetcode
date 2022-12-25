class Solution {
public:
    

    
    
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int walkedRight = 0, walkedLeft = 0;
        int res1 = INT_MAX, res2 = INT_MAX;
        int i = startIndex;
        while(words[i] != target && walkedRight < words.size() * 2)
        {
            ++i;
            i %= words.size();
            ++walkedRight;
            
        }
        if(words[i] == target)
        {
            res1 = walkedRight;
        }
        
        i = startIndex;
        while(words[i] != target && walkedLeft < words.size() * 2)
        {
            --i;
            if(i == -1)
                i = words.size() - 1;
            ++walkedLeft;
        }
        if(words[i] == target)
        {
            res2 = walkedLeft;
        }        
        
        if(res1 != INT_MAX || res2 != INT_MAX)
            return min(res1,res2);
        
        return -1;
    }
};