class Solution {
public:
    /*
        这道题给出用户按下的按键，我们要找出所有的字母组合
        比如说2代表abc 3代表 def
        22的组合就有aa ab ac ba bb bc ca cb cc
        23有ad ae af bd be bf cd ce cf
        
        我们可以认为每次遇到一个按键，我们就要把这个按键对应的所有组合append到已有的所有组合中。
        在一开始，我们只有一个[] 空组合
        遇到2
        有了a,b,c
        再遇到2
        有了aa,ab,ac,ba,bb,bc,ca,cb,cc
        遇到3，有了aad,aae,aaf,abd,abe,abf,...
        
        我们首先应该创建一个映射表
    */
    
    vector<char> getCombinationFromDigit(int digit)
    {
        vector<char> ans;
        for(int i =0; i < 3; ++i)
        {
            //97 + 0 + (2 -2) * 3 = 97:a
            //97 + 0 + (3 - 2) * 3 = 100:d
            //97 + 1 + (3 - 2) * 3 = 101:e
            char chr;
            chr = 97 + i +  (digit - 2) * 3;
            if(digit > 7)
                ++chr;
            ans.emplace_back(chr);
        }
        if(digit == 7)
            ans.emplace_back('s');        
        if(digit == 9)
            ans.emplace_back('z');
        return ans;
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> res(1);//默认有一个空字符串
        
        for(char digit : digits)
        {
            int unchanged_size = res.size();
            for(int i = 0; i < unchanged_size; ++i)
            {
                //把新的组合加入到已有的数据上。
                vector<char> combo = getCombinationFromDigit(digit - 48);//ASCII转数字
                string old_data = res[i];
                for(int j = 0; j < combo.size();++j)
                {
                    if(j == 0)
                        res[i] = old_data + combo[j];//第一个新组合直接加在已有的组合上，别的要新增
                    else
                        res.emplace_back(old_data + combo[j]);
                }
            }
            //cout << digit;
        }
        
        return res[0] == "" ? vector<string>() : res;
    }
};