class Solution {
public:

    void mergeSort(vector<int>& vec, int begin, int end)
    {
        if (begin >= end)
            return;

        int mid = (begin + end) / 2;
        mergeSort(vec, begin, mid);
        mergeSort(vec, mid + 1, end);
        vector<int> ans(end - begin + 1);

        int pV1 = begin,pV2 = mid + 1;
        int i = 0;
        while(pV1 <= mid || pV2 <= end)
        {
            if(pV1 <= mid && (pV2 > end || vec[pV1] < vec[pV2]))
                ans[i] = vec[pV1++];
            else
                ans[i] = vec[pV2++];
            ++i;
        }
        i = begin;
        for(auto&& tmp : ans)
        {
            vec[i] = tmp;
            ++i;
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0, nums.size() - 1);
        return nums;
    }
};