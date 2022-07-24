class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        /*
            假如说我们有
            A
            BC
            DEF
            权重为
            1
            12
            232
            使用Dijstra的算法
            首先每个顶点的距离都是无穷远

            A  1 
            B  2 A
            C  3 A
            D  4 B
            E  5 B
            F  5 C

            现在可以发现， DEF里面最小值是4.
            如果是

            2
            34
            561

            A 2
            B 5  A
            C 6  A
            D 10 B
            E 11 B
            F 7  C

            可以发现最小值是 7

        */
        int elementCount = (triangle.size() * (triangle.size() + 1)) / 2;
        int distanceData[elementCount]; //因为三角形每一行会多一个节点，所以行数决定了最多会有多少个元素。
        distanceData[0] = triangle[0][0];//第一个顶点的距离就是第一个顶点的距离本身。

        for(int i=1; i < triangle.size(); i++)
        {
            for(int j =0; j < i + 1;j++)//第一次循环1次，第二次循环2次，处理三角形里面的每个元素。
            {
                int row = i;
                int lastRowEnd = ((row * (row + 1)) / 2);//本行的起点
                int lastRow = lastRowEnd- row;//    上一行的起点
                
                if(j == 0)//如果我们在本行第一个，那么不考虑上一行左边的
                {
                    //等于本顶点加上正上方的
                    distanceData[lastRowEnd] = triangle[i][j] + distanceData[lastRow];
                }
                else if(j == i)//当前列等于行，也就是最右边，不考虑正上方的
                {
                    //等于本顶点加上左上方的
                    distanceData[lastRowEnd + j] = triangle[i][j] + distanceData[lastRow + j - 1];
                }
                else//处在中间，要选正上方或者左上方之间更小的哪个。
                {
                    distanceData[lastRowEnd + j] = triangle[i][j] + 
                        min(distanceData[lastRow + j],distanceData[lastRow + j - 1]);
                }
            }
        }
                                         
        //从最后一行里面选数值最小的
        int min = distanceData[elementCount - 1];
        
       for(int i = elementCount - 2; - (i - (elementCount - 2)) < (triangle.size() - 1); i--)
         {
            if(distanceData[i] < min)
                min = distanceData[i];
         }
         
        
        return min;
    }
};