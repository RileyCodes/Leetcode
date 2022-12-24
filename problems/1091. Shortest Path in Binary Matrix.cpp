class Solution {
    int minPath = INT_MAX;
public:
    /*
    [[0,0,0],
     [0,1,0],
     [0,0,0]]
     
     DFS的问题：对角线优先
     
     [x,x,0]
     [0,1,x]
     [0,x,x] 用了五步！
     
     BFS：
     [x,0,0] 第一步
     [0,1,0]
     [0,0,0] 
     
     [x,x,0] 第二步
     [x,1,0]
     [0,0,0]  
     
     [x,x,x] 第三步
     [x,1,x]
     [x,x,0]    

     [x,x,x] 第四步
     [x,1,x]
     [x,x,x]    
     
    [0,1,0,1,0]
    [1,0,0,0,1]
    [0,0,1,1,1]
    [0,0,0,0,0]
    [1,0,1,0,0]
    
    [x,1,0,1],
    [1,0,0,0],
    [0,0,1,1],
    [0,0,0,0]
    
    [x,1,x,1],
    [1,x,x,0],
    [x,x,1,1],
    [0,0,0,0]    
    
    [x,1,x,1],
    [1,x,x,x],
    [x,x,1,1],
    [x,x,x,0]    
    
    
    [x,1,x,1],
    [1,x,x,x],
    [x,x,1,1],
    [x,x,x,x]        
    */
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
       vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size(), 0));
        
        if(grid[0][0] == 1)
            return -1;
        
       queue<pair<int,int>> q;
        
       //初始化第一层BFS的数据
       q.push(pair<int,int>(0,0));
       visited[0][0] = true;
       q.push(pair<int,int>(-1,-1));
       int depth = 1;
       while(1) 
       {
            pair<int,int> point = q.front();
            q.pop();
            if(point.first == -1 && point.second == -1)//发现层级标识符，这意味着本级中的所有节点被处理完了。
            {
                ++depth;
                
                if(q.empty())
                {
                    //处理完一层以后发现后面没东西了，下一级没有需要处理的东西，结束了。
                    break;
                }
                
                /*
                每次当我们pop完了一层的东西以后，增加一个层级标识符
                /因为这意味着我们开始处理下一层了

                想象一下队列的情况：1# -> #22 -> 22# -> 2#33 -> #33 -> 33# -> 3#4 -> #44 -> 44#
                */
                q.push(pair<int,int>(-1,-1));
                continue;
             
            }
                
           //cout << "y" << point.first << "x" << point.second << endl;
            if(point.first == grid.size() - 1 && point.second == grid[0].size() - 1)
            {
                //走到了目的地，更新发现的最小长度。 因为是BFS且我们是对角线优先，不需要找出别的可行路径来比较，第一个可行路径必然是最短路径。
                //对角线A到B走了1步，非对角线走了2步，走了2步的路径可以直接忽略掉。
                minPath = min(minPath,depth);
                break;
            }        
            
            const int direction_x[8]{1,-1,-1,1, 1,-1,0,0};
            const int direction_y[8]{1,-1,1,-1, 0,0,1,-1};  
            for(int i = 0; i < 8; ++i)
            {
                int new_x = point.first + direction_x[i];
                int new_y = point.second + direction_y[i];
                if(new_x < 0 || new_x >= visited.size() ||
                new_y < 0 || new_y >= visited[0].size()  ||
                visited[new_x][new_y] || grid[new_x][new_y] == 1)//排除掉不访问的条件。
                    continue;
                visited[new_x][new_y] = true;
                /*这里需要注意，尽管我们没有实际上访问下一层级，但是我们必须立即标记这个节点已经被访问才能避免重复访问。
                这是因为比如说A和BC近邻，BC互相也近邻，那么第一级的A发现了近邻的B和C，把BC加入下一级的处理队列。
                然而，处理B的时候还没访问C，那么由于B和C也近邻，这会导致处理B的时候又把C安排到下一级去访问。*/

                q.push(pair<int,int>(new_x,new_y));
            }
       }

       return minPath == INT_MAX? -1 : minPath; 
    }
};

