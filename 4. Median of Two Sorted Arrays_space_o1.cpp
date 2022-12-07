class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int totalSize = nums1.size() + nums2.size();
    vector<int>* curArray = &nums1;
    vector<int>* nextArray = &nums2;
    pair<int, int> curIndices(0, 0);
    pair<int, int> nextIndices;

    for (int curPos = 0; curPos <= (totalSize - 1) / 2; ++curPos) {
        int pointerMoved = -1;
        if (curIndices.first < nums1.size() && (curIndices.second >= nums2.size() || nums1[curIndices.first] < nums2[curIndices.second])) {
        ++curIndices.first;
        pointerMoved = 1;
        } else if (curIndices.second < nums2.size()) {
        ++curIndices.second;
        pointerMoved = 2;
        }

        if (curPos == (totalSize - 1) / 2) {
        curArray = (pointerMoved == 1) ? &nums1 : &nums2;
        }
    }

    if (totalSize % 2 == 0) {
        nextIndices = curIndices;
        if (nextIndices.first < nums1.size() && (nextIndices.second >= nums2.size() || nums1[nextIndices.first] < nums2[nextIndices.second])) {
        ++nextIndices.first;
        nextArray = &nums1;
        } else if (nextIndices.second < nums2.size()) {
        ++nextIndices.second;
        nextArray = &nums2;
        }
    }

    double res = (*curArray)[(curArray == &nums1) ? curIndices.first - 1 : curIndices.second - 1];
    if (totalSize % 2 == 0) {
        res = (res + (*nextArray)[(nextArray == &nums1) ? nextIndices.first - 1 : nextIndices.second - 1]) / 2.0f;
    }
    return res;
    }
};