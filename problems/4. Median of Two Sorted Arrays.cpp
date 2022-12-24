class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;

        int i1 = 0 , i2 = 0;
        while(1)
        {
            if(i1 >= nums1.size() && i2 >= nums2.size())
                break;

            if(i1 < nums1.size() && (i2 >= nums2.size() || nums1[i1] < nums2[i2]))
            {
                nums3.emplace_back(nums1[i1]);
                ++i1;
            }
            else
            {
                nums3.emplace_back(nums2[i2]);
                ++i2;
            }
        }
        double res = 0;
        if(nums3.size() % 2 == 0)
        {
            int index = (nums3.size() - 1) / 2;
            res = (nums3[index] + nums3[index + 1]) / 2.0f;
        }
        else
        {
            int index = nums3.size() / 2;
            res = nums3[index];
        }
        return res;
    }
};