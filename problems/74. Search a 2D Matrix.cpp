class Solution {
public:
    
    /*这道题其实就是在矩阵而不是在数组中做对已排序数据的二分查找
    直接把矩阵当数组处理就可以了。
    比如说,[0]在[0][0],[3]在 3 / 4 = 0 第0行第[3]个
    [7] 在 7 / 4 = 1，在第[1]行
    7 % 4 = 3,在第[3]个，所以是[1][3]
    第[10]个在10 / 4 = 第二行
    10 % 4 第[2]个，所以是[2][2]
    
    让矩阵对算法透明，做一个接口负责把数组操作转为矩阵操作。
    */
    
    int* arrayIndexToMatrix(vector<vector<int>>& matrix, int index)
    {
        return &matrix[index / matrix[0].size()][index % matrix[0].size()];
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lP = 0, rP = matrix.size() * matrix[0].size() - 1;//先乘除后加减，不用加括号。 要 -1 是因为我们访问索引是从0开始计数的。
        while(lP <= rP)
        {
            int mid = (lP + rP) / 2;
            if(*arrayIndexToMatrix(matrix,mid) == target)
                return true;
            if(*arrayIndexToMatrix(matrix,mid) > target) //向左搜索
                rP = mid - 1;
            else
                lP = mid + 1;
            
        }

        return false;
    }
}; 