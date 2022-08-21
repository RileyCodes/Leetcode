class Solution {
public:
    string largestPalindromic(string num) {
        
        vector<int> digitCounter(10);
        
        for(int i = 0; i < num.size();++i)
        {
            //cout << num[i] << endl;
            ++digitCounter[(int)num[i] - 48];
        }
        num.clear();
        
        //sort(digitCounter.begin(),digitCounter.end());
        /*
        for(int i = 0; i < digitCounter.size();++i)
        {
            cout << "i:" << i <<" "<< digitCounter[i] << endl;
        }*/
        string mid;

        string & ans_left = num;
        
        bool isHadSingle = false;
        for(int i = digitCounter.size() - 1; i > 0; --i)
        {
            while(digitCounter[i] != 0)
            {
                if(digitCounter[i] - 1 > 0)
                {
                    ans_left += (((char)(i + 48)));
                    digitCounter[i] -= 2;
                }
                else if(digitCounter[i] - 1  == 0)
                {
                    if(!isHadSingle)
                    {
                        mid += (((char)(i + 48)));                      
                    }
                    isHadSingle = true;
                    --digitCounter[i];  
                }   
            }   
        }
        
        if(ans_left.size() > 0)
        {
            while(digitCounter[0] - 1 > 0)
            {
                    ans_left += '0';
                    digitCounter[0] -= 2;
            }            
        }

        if(ans_left.size() == 0 && !isHadSingle)
        {
            for(int i = digitCounter.size() - 1; i > 0; --i)
            {
                if(digitCounter[i] > 0)
                {
                    mid = (char)(i + 48);
                    isHadSingle = true;
                }
            }            
            
            if(!isHadSingle)
            {
                if(digitCounter[0] > 0)
                    return "0";                
            }

        }
        else if(digitCounter[0] - 1 == 0 && !isHadSingle)
        {
            mid += '0';
        }

        num = num + mid;
        
        if(mid.size() > 0)
        {
            for(int i = num.size() - 2; i >=0; --i)
            {
                num += num[i];
            }            
        }
        else
        {
            for(int i = num.size() - 1; i >=0; --i)
            {
                num += num[i];
            }            
        }
        
            

        
        return num;
    }
};