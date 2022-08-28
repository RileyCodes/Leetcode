class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int timeSpendG = 0, timeSpendP = 0, timeSpendM = 0;
        int travelSpendM = 0, travelSpendP = 0, travelSpendG = 0;
        //这道题MPG应该用数组的，但是我赶时间没用。
        int sumArr[travel.size()];
        
        //前缀和
        for(int i = 0; i < travel.size(); ++i)
        {
            if(i == 0)
                sumArr[0] = travel[0];
            else
                sumArr[i] = sumArr[i - 1] + travel[i];
        }
        
        for(int i = 0; i < garbage.size(); ++i)
        {
            //扫描垃圾
            bool hasM = false,hasP = false,hasG = false;
            for(int j = 0; j < garbage[i].size(); ++j)
            {
                //对应卡车增加时间
                if(garbage[i][j] == 'M')
                {
                    ++timeSpendM;
                    hasM = true;
                }   
                if(garbage[i][j] == 'P')
                {
                    ++timeSpendP;
                    hasP = true;
                }
                if(garbage[i][j] == 'G')
                {
                    ++timeSpendG;
                    hasG = true;
                }
                if(hasM && i > 0)
                {
                    //如果我们在这里发现了垃圾，那么这意味着垃圾车必须花时间来到这里，计算从最开始来到这里需要的时间
                    //注意我们的前缀和中，[0]代表的是从[0]走到[1]的时间
                    //所以，当i = 1的时候（第二家），我们的旅行时间是[0]
                    travelSpendM = sumArr[i - 1];
                }
                if(hasP && i > 0)
                {
                    travelSpendP = sumArr[i - 1];
                }
                if(hasG && i > 0)
                {
                    travelSpendG = sumArr[i - 1];
                } 
            }
        }
        
        return timeSpendG + timeSpendP + timeSpendM + travelSpendM + travelSpendP + travelSpendG;
        
    }
};