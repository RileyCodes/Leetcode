class Solution {
public:
    
    
    void binraryInc(vector<int>& arr,int& totalOne)
    {
        for(int i = arr.size() - 1; i >= 0;--i)
        {
            if(arr[i] == 0)
            {
                arr[i] = 1;
                ++totalOne;
                
                for(int j = i + 1; j < arr.size(); ++j)
                {
                    arr[j] = 0;
                    --totalOne;
                }
                return;
            }
        }
        
        
        
    }
    
    vector<int> countBits(int n) {
        vector<int> ans(1);
        
        vector<int> arr(17);
        int oneCount = 0;
        for(int i = 0 ; i < n; ++i)
        {
            binraryInc(arr,oneCount);            
            ans.emplace_back(oneCount);
        }
        
        return ans;
    }
};