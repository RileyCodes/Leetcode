class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> q;
        for(auto&& num: nums)
            q.push(num);
        
        unsigned long long score = 0;
        for(int i = 0; i < k ;++i)
        {
            auto ele = q.top();
            cout << ele << endl;
            score += ele;
            q.pop();
            q.push(ceil((double)ele/  (double)3));            
        }

        return score;        
    }
};