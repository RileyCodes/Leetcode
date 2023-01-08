class Solution {
public:
    bool isItPossible(string word1, string word2) {
        unordered_map<char,int> m1, m2;
        
        for(auto&& chr : word1)
            ++m1[chr];
        for(auto&& chr : word2)
            ++m2[chr];
        
        int d1Cnt = 0, d2Cnt = 0;
        for(auto&& cnt : m1)
        {
            if(cnt.second != 0)
                ++d1Cnt;
        }
        
        for(auto&& cnt : m2)
        {
            if(cnt.second != 0)
                ++d2Cnt;
        }      
        
        int diff = d1Cnt - d2Cnt;
        //cout << d1Cnt << endl;
        //cout << d2Cnt << endl;
                
        
        for(int i = 0; i < 26; ++i)
        {
            char chr = i + 'a';
            if(m1.count(chr) == 0)
                continue;
            
            for(int j = 0; j < 26;++j)
            {
                char targetChr = j + 'a';
                //cout << "chr " << chr << " tChr" << targetChr << endl;
                
                if(m2.count(targetChr) == 0)
                    continue;
                int dm1 = -(m1[chr] - 1 == 0);
                //cout << "dm1 " << dm1 << endl;
                dm1 += m1.count(targetChr) == 0;
                //cout << "dm1 " << dm1 << endl;
                
                int dm2 = m2.count(chr) == 0;
                //cout << "dm2 " << dm2 << endl;
                dm2 += -(m2[targetChr] - 1 == 0);
                //cout << "dm2 " << dm2 << endl;
                
                if(targetChr == chr)
                {
                    dm1 = 0;
                    dm2 = 0;
                }
                if(diff + dm1 - dm2 == 0)
                    return true;
            }
            
        }
        

        return false;
    }
};