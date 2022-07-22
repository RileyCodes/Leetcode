class Solution {
    void swap(int &a,int &b)
    {
        int tmp = b;
        b = a;
        a = tmp;
    }
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        int lIndex = 0;
        int rIndex = k;
        int solvedCount = 0;
        if(k == 0)
            return;
        while(1)
        {
            swap(nums[lIndex], nums[rIndex]);
            rIndex = (rIndex + k) % nums.size();
            if(rIndex == lIndex)
            {
                ++lIndex;
                rIndex = lIndex + k;           
                solvedCount += 2;
            }
            else
            {
                ++solvedCount;
            }
            
            if(solvedCount == nums.size())
                return;
            
            //if(lIndex >= gcd(k,nums.size()))
            //    return;     
        }
    }
};