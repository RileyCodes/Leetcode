class Solution {
public:
    vector<int> pSum;
    Solution(vector<int>& w) {
        pSum.resize(w.size());
        pSum[0] = w[0];
        for(int i = 1; i < w.size(); ++i)
            pSum[i] = pSum[i - 1] + w[i];

        //srand(time(0));
    }
    
    int pickIndex() {
        
        int target = rand() % pSum.back();
        
        
        int lP = 0, rP = pSum.size();
        int ans = -1;
        while(lP < rP)
        {
            int mid = (lP + rP) / 2;
            if(pSum[mid] <= target)
                lP = mid + 1;
            else if(pSum[mid] > target)
            {
                ans = mid;
                rP = mid;
            }
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */