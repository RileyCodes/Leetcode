class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lP = 0;
        int rP = numbers.size() - 1;
        vector<int> nums;
        while(lP < rP)
        {
            int numberNeeded = target - numbers[lP];
            if(numbers[rP] == numberNeeded)
            {
                
                nums.emplace_back(lP + 1);
                nums.emplace_back(rP + 1);
                return nums;
            }
            if(numbers[rP] > numberNeeded)
                rP--;
            else
                lP++;
        }
        return nums;
    }
};