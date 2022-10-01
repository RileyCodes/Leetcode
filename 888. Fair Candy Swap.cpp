class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        vector<int> ans;
        int aSum = 0, bSum = 0;
        set<int> aBoxCnt,bBoxCnt;
        for(auto cnt : aliceSizes)
        {
            aSum += cnt;
            aBoxCnt.insert(cnt);
        }
        for(auto cnt : bobSizes)
        {
            bSum += cnt;
            bBoxCnt.insert(cnt);
        }
        
        for(auto aCnt : aBoxCnt)
        {
            int diff = aSum - bSum;
            diff = diff - aCnt  * 2;
            int bExchange = -(diff /2);
            
            if(bBoxCnt.count(bExchange) > 0)
            {
                ans.emplace_back(aCnt);
                ans.emplace_back(bExchange);
                break;
            }
        }
        return ans;
    }
};