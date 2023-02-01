class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      vector<int> nums3;

      int lP = 0, rP = 0;
      while(lP < nums1.size() || rP < nums2.size())
      {
        if(lP < nums1.size() && (rP >= nums2.size() || nums1[lP] < nums2[rP]))
        {
          nums3.emplace_back(nums1[lP]);
          ++lP;
        }
        else
        {
          nums3.emplace_back(nums2[rP]);
          ++rP;
        }
      }

      if(nums3.size() % 2 != 0)
        return nums3[nums3.size() / 2];

      int mid = (nums3.size() - 1) / 2;
      return (double)(nums3[mid] + nums3[mid + 1]) / (double)2;      
    }
};