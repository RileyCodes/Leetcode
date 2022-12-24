class Solution {
public:
    
    inline int signFunc(int num)
    {
        if(num > 0)
            return 1;
        else if(num == 0)
            return 0;
        return -1;        
    }
    
    int arraySign(vector<int>& nums) {
        long long res = 1;
        for(int i = 0; i < nums.size(); ++i)
        {
            res *= signFunc(nums[i]);
        }
        
        return signFunc(res);
    }
};