class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        vector<int> ans;
        
        int p1 = 0, p2 = 0;
        
        while(p1 < nums1.size() && p2 < nums2.size())
        {

            if(nums1[p1] > nums2[p2])
            {
                ++p2;
            }
            else if(nums1[p1] < nums2[p2])
            {
                ++p1;
            }
            else
            {
                if(ans.size() > 0 && ans[ans.size() - 1] == nums1[p1])
                {
                    ++p1;
                    continue;
                }
                ans.emplace_back(nums1[p1]);
            }            
        }
        return ans;
    }
};