class Solution {
public:
    //排列组合：   
    
    long long _uniquePaths(int n, int r,int k)
    {
        //n = 10 , r = 9 , k(n - r) = 1
        //n = 7, r = 4, k = 3
        //因此，我们的n-r做除法的时候不需要担心 出现n == r了，k还没除到1的情况。
        //n代表原本要阶乘的数量（组合公式的分子）,r是r，k是n-r。
        //为什么这样除出来的一定是整数，不会有信息丢失？？？
        
        if(n == r)
            return 1;
        
        return (n * _uniquePaths(n - 1,r,k - 1)) / k;
    }
    
    int uniquePaths(int m, int n) {
   
        /*
        排列的数量：既然我们要从左上角走到右下角，棋盘大小是m宽度和n高，我们至少要走m－1次右和n－1次左。
        因此，可以认为我们是在一个(m-1+n-1)大小的操作序列里面填空，选择这次走右还是走左。
        比如说我们一开始有5个空，现在就有5个填法，右可以出现在第一个 也可以出现在最后一个空里面
        让我们填写了第一个空以后，还剩下4个选择。
        所以最终排列数量就是5＊4＊3...
        一直到穷尽右的数量为止，不会一直到1，因为我们除了要填m－1个右，还要填n－1个下。
        来看看4个空，2个右2个下
        m＝3 n ＝ 3
        4!/2! 居然不对。。
        这是因为不重复组合的公式是：
        n!/(r!(n-r)!)
        我们的n是(m+n-2)
        r是(m-1) or (n - 1)
        */
        
        if(min(m,n) == 1)//如果是一维的，就只有一个解法
            return 1;
        
        int res = 0;
        int r = m < n ? (m - 1) : (n - 1);
        int n_ = m + n -2;
        int n_r = n_ - r;
        
        cout <<r << endl;
        cout <<n_r << endl;
        res = _uniquePaths(n_,n_r,r);
        return res;
    }
};