class Solution {
public:
    /*
        这道题要求给出括号的数量，找出所有可行的括号组合。
        比如说 n = 1 就只有 ()
        n = 2 就有()()和(())
        n = 3 有()()(),(()())和((())),还有(())()和()(()) （注意：似乎AB和BA被视为2个组合）
        
        因为n等于括号的数量，所以n也等于左括号或右括号的数量。
        我们可以想象n等于我们必须花掉的左括号的数量，然后找出所有的花法
        我们有哪些花法？
        
        1.()
        2.(())
        3.((()))
        4.()()
        5.(())()
        6.()(())
        ...
        不管有哪些花法，无非就是一种是左括号越加越多，还一种是先配对，可以用递归分裂出穷举所有可能性的组合，然后只拿配对完成的结果。
    */
    
    void _generateParenthesis(vector<string>& result, int l,int r,string combo)
    {
        //我们有每次递归多一个左括号的做法
        if(l > 0)
        {
            string local_combo = combo;
            local_combo += "(";
            _generateParenthesis(result,l - 1,r,local_combo);
        }
        //我们也有每次递归配对一个括号的做法
        if(r > l)
        {
            string local_combo = combo;
            local_combo += ")";
            _generateParenthesis(result,l,r - 1,local_combo);
        }
        //通过以上递归，我们分裂出了可以穷举所有组合的递归
        
        //只保存把括号花完并且左右都配对完了的结果。
        if(l == 0 && r == 0)
            result.emplace_back(combo);
    }
    
    
    
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        
        _generateParenthesis(result, n,n,"");
        
        return result;
    }
};