class Solution {
public:


    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        priority_queue<pair<int,int>> q;
        vector<int> ans(nums1.size());

        for(int i = 0; i < nums2.size(); ++i)
        {
            q.push(pair<int,int>(nums2[i], i));
        }

        int lP = 0, rP = nums1.size() - 1;

        while(lP <= rP)
        {
            if(nums1[rP] > q.top().first)
            {
                ans[q.top().second] = nums1[rP];
                --rP;
            }
            else
            {
                ans[q.top().second] = nums1[lP];
                ++lP;
            }
            q.pop();
        }

        return ans;
    }
};