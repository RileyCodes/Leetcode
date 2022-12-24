class Solution {
public:

    bool isBoundary(int x, int y, int left, int top, int right, int bottom)
    {
        if(x < left)
            return true;
        if(x > right)
            return true;
        if(y < top)
            return true;
        if(y > bottom)
            return true;
        return false;
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int x = 0, y = 0;
        int left = 0, top = 0, right = matrix[0].size() - 1, bottom = matrix.size() - 1;
        int dir_x[] = {1,0,-1,0};
        int dir_y[] = {0,1,0,-1} ;
        int incdecTable[] = {1,-1,-1,1};
        vector<int> ans;
        int dirIndex = 0;
        int* refTable[4] = {&top, &right, &bottom, &left};
        ans.emplace_back(matrix[y][x]);
        while(!(right - left < 0 && bottom - top < 0))
        {
            if(isBoundary(x + dir_x[dirIndex], y + dir_y[dirIndex], left, top, right, bottom))
            {
                (*refTable[dirIndex]) += incdecTable[dirIndex];
                ++dirIndex %= 4;
                continue;
            }

            x += dir_x[dirIndex];
            y += dir_y[dirIndex];
            ans.emplace_back(matrix[y][x]);
        }
        return ans;
    }
};