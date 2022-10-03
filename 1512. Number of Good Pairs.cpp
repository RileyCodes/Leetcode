class Solution {
    
    
    long long combo_count(int n, int r,int k)
    {
        if(n == r)
            return 1;
        return (n * combo_count(n - 1,r,k - 1)) / k;
    }
    
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        
        vector<int> counter(101);
        for(int i = 0 ; i < nums.size(); ++i)
        {
            ++counter[nums[i]];
        }
        
        int cnt = 0;
        for(int i = 0; i < counter.size(); ++i)
        {
            if(counter[i] > 1)
                cnt += combo_count(counter[i],counter[i] - 2,2);
        }
        return cnt;
    }
};