class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        for(int i = digits.size() -  1 ; i >=0 ; --i)
        {
            if(digits[i] < 9)
            {
                
                ++digits[i];
                for(int j = i + 1; j < digits.size();++j)
                {
                    digits[j] = 0;
                }

                return digits;
            }
        }
        
        vector<int> ans;
        ans.emplace_back(1);
        for(int i = 0 ; i < digits.size();++i)
        {
            ans.emplace_back(0);
        }
        return ans;
    }
};