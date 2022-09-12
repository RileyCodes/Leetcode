class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> numInWindow;
        
        int i = 0;
        int j = 0;
        
        while(j < nums.size())
        {
            if(j - i > k)
            {
                numInWindow.erase(nums[i]);
                i++;
            }
            else
            {
                if(numInWindow.count(nums[j]) != 0)
                {
                    cout << "i " << i << " j " << j << endl;
                    return true;
                }

                numInWindow.insert(nums[j]);
                j++;
            }

        }
        return false;
    }
};