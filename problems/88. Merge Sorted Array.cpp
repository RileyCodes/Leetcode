class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans(nums1.size());
        int count = 0;
        int i = 0, j = 0;
        
        while(i < m && j < n)
        {
            if(nums1[i] <= nums2[j])
            {
                ans[count++] = nums1[i];
                ++i;
            }
            else
            {
                ans[count++] = nums2[j];
                ++j;
            }
        }
        
        while(i < m)
        {
            ans[count++] = nums1[i++];
        }
        
        
        while(j < n)
        {
            ans[count++] = nums2[j++];
        }        
        
        nums1 = ans;
        
        return;
    }
};