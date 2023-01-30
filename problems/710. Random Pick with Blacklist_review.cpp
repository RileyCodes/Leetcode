class Solution {
public:

    unordered_map<int, int> m;
    int n;
    int range;
    Solution(int n, vector<int>& blacklist) 
    {
        this->n = n;
        range = n - blacklist.size();
        
        for(auto&& b : blacklist)
            m[b] = -1;

        int last = n - 1;
        for(auto&& key : m)
        {
            if(key.first >= range)
                continue;
            while(m.count(last))
                --last;
                
            m[key.first] = last;
            --last;
        }
    }
    
    int pick() 
    {
        int selectedNum = rand() % range;
        
        if(m.count(selectedNum))
        {
            return m[selectedNum];
        }
            
        
        return selectedNum;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */