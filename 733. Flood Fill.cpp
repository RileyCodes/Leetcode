class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        bool visited[image.size()][image[0].size()];

        for(int i=0; i < image.size();i++)
        {
            for(int j=0; j < image[0].size();j++)
            {
                visited[i][j] = false;
            }
        }
        
        int startingColor = image[sr][sc];
        std::queue<std::pair<int,int>> que;
        que.push(std::make_pair(sr,sc));
        while(!que.empty())
        {
            std::pair<int,int> point = que.front();
            que.pop();
            
            sr = point.first;
            sc = point.second;
            
            if(image[sr][sc] == startingColor)
                image[sr][sc]  = color;
            
            int direction_x[4] = {-1,1,0,0};
            int direction_y[4] = {0,0,-1,1};
            
            for(int i=0 ; i < 4;i++)
            {
                if(sr + direction_x[i] >= 0 && sr + direction_x[i] < image.size() &&
                   sc + direction_y[i] >= 0 && sc + direction_y[i] < image[0].size() &&
                    image[sr + direction_x[i]][sc + direction_y[i]] == startingColor &&
                   !visited[sr + direction_x[i]][sc + direction_y[i]])
                {
                    visited[sr + direction_x[i]][sc + direction_y[i]] = true;
                    que.push(std::make_pair(sr + direction_x[i],sc + direction_y[i]));
                }
            }

        }
        return image;
    }
};