class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int diff[20002]{0};


        for(auto&& booking : bookings)
        {
            diff[booking[0]] += booking[2];
            diff[booking[1] + 1] -= booking[2];
        }

        vector<int> ans;
        int bookingsIndex = 0;
        for(int i = 1; i < 20001;++i)
            diff[i] += diff[i - 1];

        for(int i = 1; i <= n ; ++i)
        {
            ans.emplace_back(diff[i]);
        }
        

        return ans;
    }
};