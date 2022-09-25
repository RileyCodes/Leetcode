class Solution {
public:
    string removeDuplicates(string s) {
        bool isDeleted = false;
        vector<int> block_list;
        
        do
        {
            isDeleted = false;
            for(int i = 1 ; i < s.size(); ++i)
            {
                if(s[i - 1] == s[i])
                {
                    isDeleted = true;
                    
                    int lP = i - 1;
                    int rP = i;
                    
                    int delLeft = -1;
                    int delRight = -1;
                    
                    while(lP >= 0 && rP < s.size())
                    {
                        if(s[lP] == s[rP])
                        {
                            delLeft = lP;
                            delRight = rP;
                        }
                        else
                            break;
                        
                        --lP;
                        ++rP;
                    }
                    
                    if(delLeft > 0)
                        s = s.substr(0,delLeft) + s.substr(delRight + 1);
                    else
                        s = s.substr(delRight + 1);
                    
                    break;
                }
            }
        }
        while(isDeleted);
        
        return s;
    }
};