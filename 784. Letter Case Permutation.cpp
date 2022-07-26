class Solution {
    bool isUpperCase(char s)
    {
        return s >= 65 && s <= 90 ;
    }
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        
        int letterIndex[12];
        int count = 0;
        for(int i=0; i < s.size(); ++i)
        {
            if(s[i] >= 97 && s[i]  <= 122)
            {
                letterIndex[count++] = i;//先把所有字母的坐标加进去
            }
            else if(isUpperCase(s[i]))
            {
                s[i] += 32;
                letterIndex[count++] = i;//确保全局小写
            }
        }
        
        result.emplace_back(s);//保存初始状态
        
        if(count == 0)
            return result;//如果没有字母 就原样返回
        
        int cur = count - 1;
        
        while(cur >= 0)
        {
            if(!isUpperCase(s[letterIndex[cur]]))//发现小写字母，改成大写，并且确保后面的全部变成小写,然后从最右边重新开始
            {
                s[letterIndex[cur]] -= 32;
                
                ++cur;
                for(;cur < count; cur++)
                {
                    //按理来说，如果当前位是大写，那么后面的应该全部都是大写，所以不需要判断
                    s[letterIndex[cur]] += 32;
                }
                --cur;
                //产生了变化，应该保存起来
                result.emplace_back(s);
            }
            else//发现了大写字母，应该左移找到非大写
            {
                cur--;
            }
        }

        return result;
    }
};