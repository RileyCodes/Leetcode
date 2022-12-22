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

    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>> ans(n, vector<int>(n));

        int x = 0, y = 0;
        int left = 0, top = 0, right = n - 1, bottom = n - 1;
        int dir_x[] = {1,0,-1,0};
        int dir_y[] = {0,1,0,-1} ;
        int incdecTable[] = {1,-1,-1,1};

        int dirIndex = 0;
        int* refTable[4] = {&top, &right, &bottom, &left};
        int i = 2;
        ans[0][0] = 1;
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
            ans[y][x] = i;
            ++i;
        }
        return ans;
    }
};