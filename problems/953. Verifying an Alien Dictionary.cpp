class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> m;
        
        for(int i = 0; i < order.size(); ++i)
        {
            m[order[i]] = i;
        }
        
        
        for(int i = 1; i < words.size(); ++i)
        {
            int maxLen = max(words[i].size(),words[i - 1].size());
            for(int j = 0 ; j < maxLen; ++j)
            {
                int order1 = (j < words[i - 1].size())? m[words[i - 1][j]] : -1;
                int order2 = (j < words[i].size())? m[words[i][j]] : -1;
                

                if(order1 < order2)//Ex: we have axxx bxxxx, since a always at top of b, no need futher check.
                    break;
                if(order1 > order2)
                {
                    
                    cout << "order1 " << order1 << endl;
                    cout << "order2 " << order2 << endl;
                    
                    return false;   
                }
            }
        }
        
        return true;
    }
};