class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size());

        for(int i = 0 ; i < ans.size() ; ++i)
            ans[i] = -1;


        int ansIndex = nums.size() * 2 - 1;

        stack<int> s;
        s.push(nums[nums.size() - 1]);
        
        for(int i = (nums.size() * 2 - 1); i >=0; --i)
        {
            
            int index = i % nums.size();
            while(!s.empty() && nums[index] >= s.top())
                s.pop();

            if(!s.empty() && nums[index] < s.top())
            {
  
                ans[ansIndex % nums.size()] = s.top();
            }
            s.push(nums[index]);
            ansIndex--;
        }

        return ans;
    }
};