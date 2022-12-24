class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> answer(queries.size());
        
        sort(nums.begin(),nums.end());
        
        for(int k = 0; k < queries.size(); ++k)
        {
            int sum = 0;
            int count = 0;
            for(int i = 0; i < nums.size(); ++i)
            {
                if((sum + nums[i]) <= queries[k])
                {
                    sum += nums[i];
                    ++count;
                }
            }    
            answer[k] = max(answer[k],count);
        }
        return answer;
    }
};