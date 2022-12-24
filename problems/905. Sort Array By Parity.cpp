class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        //Solution 1
        /*sort(nums.begin(),nums.end(),[&](const auto& v1,const auto& v2){
            if(v1 % 2 == 0 and v2 % 2 != 0)
                return true;
            return false;
        });*/
        
        //Solution 2
        vector<int> ans(nums.size());
        int lP = 0;
        int rP = nums.size() - 1;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] % 2 == 0)
                ans[lP++] = nums[i];
            else
                ans[rP--] = nums[i];
        }
        return ans;
    }
};