class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        vector<string> ans;
        if(nums.size() == 0)
            return ans;
        
        int lastNum = nums[0];
        int count = 0;
        
        bool hasRange = false;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(lastNum == nums[i])
            {
                string s;
                s += std::to_string(nums[i]);
                ans.emplace_back(s);
            }
            else if(lastNum + 1 == nums[i])
            {
                if(i + 1 == nums.size())
                {
                    ans[count] += "->";
                    ans[count] += std::to_string(nums[i]);
                }
                else
                {
                    ++lastNum;
                    hasRange = true;
                }
            }
            else
            {
                if(hasRange)
                {
                    ans[count] += "->";
                    ans[count] += std::to_string(nums[i - 1]);                    
                }
                hasRange = false;

                ++count;
                
                lastNum = nums[i];
                string s;
                s += std::to_string(nums[i]);
                ans.emplace_back(s);                
            }
            
        }
        
        return ans;
    }
};