class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int totalSize = nums1.size() + nums2.size();
        bool isEven = totalSize % 2 == 0;

        vector<int>* v = nums1.size() != 0 ? &nums1 : &nums2;
        int nums1Index = 0, nums2Index = 0;
        int targetIndex = (totalSize - 1) / 2;
        int curLocalIndex = 0;

        for(int curIndex = 0; curIndex <= targetIndex; ++curIndex)
        {
          if(nums1Index < nums1.size() && 
          (nums2Index >= nums2.size() || nums1[nums1Index] < nums2[nums2Index]))
          {
            v = &nums1;
            curLocalIndex = nums1Index;
            ++nums1Index;
          }
          else
          {
            v = &nums2;
            curLocalIndex = nums2Index;
            ++nums2Index;
          }
        }

        if(!isEven)
          return (*v)[curLocalIndex];
        
        
        int v1, v2;
        v1 = (*v)[curLocalIndex];
        if(nums1Index < nums1.size() && 
          (nums2Index >= nums2.size() || nums1[nums1Index] < nums2[nums2Index]))
          v2 = nums1[nums1Index];
        else
          v2 = nums2[nums2Index];

        return (double)(v1 + v2) / (double)2;
    }
};