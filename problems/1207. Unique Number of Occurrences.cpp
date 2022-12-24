class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        const int map_size = 2000;
        vector<int> map(map_size);
        for(int i = 0; i < arr.size(); ++i)
        {
            int value = arr[i] + 1000;
            ++map[value % map_size];
        }
        
        sort(map.begin(),map.end());
        
        for(int i = 1; i < map_size;++i)
        {
            if(map[i - 1] == 0)
                continue;
            
            if(map[i - 1] == map[i])
                return false;
        }
        return true;
    }
};