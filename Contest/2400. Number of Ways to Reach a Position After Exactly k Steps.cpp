class Solution {
public:
    
    /*
    
    这道题我们假设startPos <= endPos
    假设向右是递增，向左是递减
    那么我们需要递增的次数，d为endPos - startPos
    比如说startPos = 0,  endPos = 2
    2 - 0 = 2.
    
    除此之外，我们还必须操作k次，也就是说，在操作了d次以后，我们还需要操作k - d次。
    比如说k = 4的话，startPos = 0,  endPos = 2 意味着我们需要向右3次，向左1次
    3 - 1 = 2.
    注意：如果k = 3则不可达。
    
    可以认为我们有一个长度为k的空，如k = 4，我们的空就是
    [][][][]
    我们需要计算出可以抵达endPos的所有填空方式，比如说[左][右][左][右]。
    
    显然这是一个组合问题，因为填空的顺序不重要，但是每个结果必须不一样
    比如说先填左：[左][] 再填右[左][右]和先填右再填左，得到的都是[左][右]，只能算一个填法，所以是组合而不是排列问题。
    
    使用组合公式(n!)/(r!*(n-r)!)解决问题。
    解决失败了，因为这道题答案就有溢出的。
    
    这道题实际上希望我们的答案是正确答案 mod 1000000007，以避免溢出
    因此，我们需要根据
    ( a + b) % c = ( ( a % c ) + ( b % c ) ) % c
    ( a * b) % c = ( ( a % c ) * ( b % c ) ) % c
    ( a – b) % c = ( ( a % c ) – ( b % c ) ) % c
    
    实现，注意我们无法使用除法（除非利用逆元）。
    因此，利用递推来解决问题。
    
    如果从0开始计算多少个办法抵达d，实际上有一种情况是数值会变成负数，因为往左走了。
    所以我们全部垫高1001，因为k最多是1000    
    */
    

    int f[2001][1001];
    
    const int mod = 1000000007;
    int dp(int cur, int k,int target)
    {
        //cout << "target " <<  target << " cur " << cur << " k " << k << " f[cur][k] " << f[cur][k] << endl;
        if(k == 0 && cur == target)
            return 1;
        if(k == 0)
            return 0;
        
        if(f[cur][k] != -1)
            return f[cur][k];
        
        if(cur + k < target)
            return 0;
        
        int res = (dp(cur + 1, k - 1, target) + dp(cur - 1, k - 1, target)) % mod;
        f[cur][k] = res;
        return res;
    }

    int numberOfWays(int startPos, int endPos, int k) {
        
        //确保startPos <= endPos
        if(startPos > endPos)
            swap(startPos,endPos);
        
        int d = endPos - startPos;//计算需要向右的次数

        for(int i = 0; i < 2001; ++i)
        {
            for(int j = 0 ; j <= k ;++j)
            {
                f[i][j] = -1;
            }
        }
        
        return dp(1000,k,d + 1000);
    }
};