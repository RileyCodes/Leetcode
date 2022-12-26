class Solution {
public:
    unordered_map<int,int> bList;
    int range = -1;
    Solution(int n, vector<int>& blacklist) {
        //[0,range]
        //n = 3, pick [0,1,2]
        //n = 5, b.size() = 2, 5 - 2 - 1 = [0,1,2]
        range = n - blacklist.size() - 1;
        int legitBound = range + 1;
        for(auto&& num : blacklist)
            bList[num] = -1;
        for(auto&& blackNum : bList)
        {
            if(blackNum.first <= range)//map to another legit num
            {
                //get a legit num from outside of boundary
                while(legitBound <=n)
                {
                    if(bList.count(legitBound) == 0)
                        break;    
                    ++legitBound;                
                }
                bList[blackNum.first] = legitBound;
                ++legitBound;
            }
        }
    }
    
    int pick() {
        int num = rand() % (range + 1);
        if(bList.count(num) > 0)
        {
            int alt = bList[num];
            if(alt != -1)
                return alt;
        }

        return num;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */