class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> cnt;
        vector<int> ans;
        

        int extraNum = -1;

        int maxNumFound = -1;
        for(auto&& num : nums)
        {
            if(cnt.count(num))
            {
                extraNum = num;
                //break;
            }
            cnt[num] = 1;
            maxNumFound = max(maxNumFound, num);
        }
        int missingNum = -1;
        for(int i = 1; i <= maxNumFound; ++i)
        {
            if(cnt.count(i) == 0)
            {
                missingNum = i;
                break;
            }
        }
        if(missingNum == -1)
            missingNum = maxNumFound + 1;

        ans.emplace_back(extraNum);
        ans.emplace_back(missingNum);
        return ans;
    }
};