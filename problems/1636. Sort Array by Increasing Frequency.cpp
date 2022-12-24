class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int counter[201]{0};
        for(int i = 0; i < nums.size(); ++i)
        {
            ++counter[nums[i] + 100];
        }
        
        sort(nums.begin(),nums.end(), [&](const auto& v1,const auto&v2){
            if(counter[v1 + 100] == counter[v2 + 100])
            {
                return v2 < v1;
            }
            return counter[v1 + 100] < counter[v2 + 100];
        });
        
        return nums;
    }
};