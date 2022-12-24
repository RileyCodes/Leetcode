class Solution {
public:
    
    int getter(int index,const vector<vector<int>>& grid)
    {
        int j = index / grid[0].size();
        int i = index % grid[0].size();
        return grid[j][i];
    }
    
    void setter(int index,vector<vector<int>>& grid, int value)
    {
        int j = index / grid[0].size();
        int i = index % grid[0].size();
        grid[j][i] = value;
    }
    
    
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> ans(grid.size(),vector<int>(grid[0].size()));
        
        int cnt = grid.size() * grid[0].size();
        for(int i = 0; i < cnt; ++i)
        {
            auto val = getter(i,grid);
            setter((i + k) % cnt, ans, val);
        }
        
        return ans;
    }
};