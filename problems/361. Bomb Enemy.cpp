class Solution {
public:
    /*
        比如说
        EE00E
        用动态规划，从左到右扫描
        就会有
        122233
        这是因为从左到右扫描的时候，最左边还不知道右边的情况
        其实一个炸弹下去都炸死3个了
        
        所以从左到右扫完以后还需要从右到左扫一遍
        12233可以理解为，当前位置往左炸能炸死几个
        这就是为什么最左边只能炸死一个，最右边往左炸能炸死3个
        从右到左扫描一遍，就能把2个方向都考虑进去 

        从右到左的话，是
        321110

        所以我们有了往左炸：
        122233
        往右炸：
        321110

        然后考虑到炸弹不能放置在有敌人的地方，
        所以我们有了往左炸：
        002203
        往右炸：
        001100
        

        可以发现2+1和3都是正确答案，扫描完了把答案合并在一起是可以的
     
     */
    int maxKilledEnemies(vector<vector<char>> &grid) {

        if(grid.size() == 0)
            return 0;

        int killableCount[grid.size()][grid[0].size()];//每个坐标能炸死多少敌人
        int count = 0;//目前找到的最大值

        //因为我们不能在有敌人的地方放炸弹，所以放置炸弹的地方必然没有敌人，不需要考虑横向和纵向敌人被重复计算的问题。

        //计算横向数据
        for(int i = 0; i < grid.size(); ++i)
        {
            int tmp = 0;
            for(int j = 0; j < grid[0].size(); ++j)
            {
                //对于每一行能炸死多少敌人，其状态转移方程只和本行有关，双重循环只是为了分别计算每一行的状态。
                //对于第一格，如果有敌人是1，否则就只能是0
                //需要注意的是，我们计算出来的都是往左炸能炸死几个，因为我们确定[i]的值的时候，还没有看过右边。
                //这就是为什么我们需要上下左右4个方向计算的原因。

                
                if(j == 0)
                    tmp = (grid[i][j] == 'E');
                else if(grid[i][j] == 'W')
                        tmp = 0;
                else if(grid[i][j] == 'E')
                        ++tmp;
                killableCount[i][j] = tmp;

            }
            //计算往右边炸的情况，这时候数组里面以及有东西了，所以我们需要+=而不是初始化
            tmp = 0;
            for(int j = grid[0].size() - 1; j >= 0; --j)
            {
                
                if(j == grid[0].size() - 1)
                    tmp = (grid[i][j] == 'E');
                else if(grid[i][j] == 'W')
                        tmp = 0;
                else if(grid[i][j] == 'E')
                        ++tmp;
                killableCount[i][j] += tmp;                
            }            
        }
        
        for(int j = 0; j < grid[0].size(); ++j)
        {
            int tmp = 0;
            for(int i = 0; i < grid.size(); ++i)
            {
                if(i == 0)
                    tmp = (grid[i][j] == 'E');
                else if(grid[i][j] == 'W')
                        tmp = 0;
                else if(grid[i][j] == 'E')
                        ++tmp;
                killableCount[i][j] += tmp;
            }

            tmp = 0;

            for(int i = grid.size() - 1; i >= 0; --i)
            {
                if(i == grid.size() - 1)
                    tmp = (grid[i][j] == 'E');
                else if(grid[i][j] == 'W')
                        tmp = 0;
                else if(grid[i][j] == 'E')
                        ++tmp;
                killableCount[i][j] += tmp;
            }
        }   


        //求最大值
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                //对于墙和敌人，都跳过
                if(grid[i][j] != '0')
                    continue;
                count = max(count, killableCount[i][j] );
            }
        }     

        return count;
    }
};