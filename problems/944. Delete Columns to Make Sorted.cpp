class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        
        int i = 0;
        bool any = false;
        
        int delCnt = 0;
        do
        {
            int lastChr = 'a';
            any = false;
            for(auto&& str : strs)
            {
                if(i < str.size())
                {
                    any = true;
                    if(lastChr > str[i])
                    {
                        ++delCnt;
                        break;
                    }
                    lastChr = str[i];
                }
            }
            ++i;
        }while(any);

        return delCnt;
    }
};