class Solution {
public:
    int missingNumber(vector<int>& nums) {
        bool counter[100000]{0};
        
        for(int i = 0 ; i < nums.size(); ++i)
        {
            counter[nums[i]] = true;
        }
        
        for(int i = 0 ; i <=nums.size(); ++i)
        {
            if(counter[i] == false)
                return i;
        }
        return -1;
    }
};