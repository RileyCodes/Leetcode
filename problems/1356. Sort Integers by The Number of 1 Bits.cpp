class Solution {
public:
    
    int CountBits(int num)
    {
        int cnt = 0;
        for(int i = 0; i < 16; ++i)
        {
            if((num & 1) == 1)
                cnt++;
            num = num >> 1;
        }
        return cnt;
    }
    vector<int> sortByBits(vector<int>& arr) {
        
        
        sort(arr.begin(),arr.end(),[&](const auto& v1,const auto& v2){
            if(CountBits(v1) == CountBits(v2))
                return v1 < v2;
            //cout << CountBits(v1) << " "<< v1 << endl;
            //cout << CountBits(v2) << " "<< v2 << endl;
            return CountBits(v1) < CountBits(v2);
        });

        return arr;
    }
};