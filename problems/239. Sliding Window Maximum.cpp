class Solution {
public:

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        list<int> lst;

        int width = 0;

        for(int i = 0; i < nums.size(); ++i)
        {
            bool have_smaller_num = false;
            do{
                have_smaller_num = lst.size() > 0 && lst.back() < nums[i];
                if(have_smaller_num)
                    lst.pop_back();
            } while(have_smaller_num);

            lst.push_back(nums[i]);

            ++width;
            if(width == k)
            {
                ans.emplace_back(lst.front());
                if(lst.front() == nums[i - k + 1])
                {
                    //cout << "pop" << lst.front() << endl;
                    lst.pop_front();
                }
                --width;
            }
        }

        return ans;
    }
};