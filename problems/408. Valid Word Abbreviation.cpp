class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        bool leadingZero = true;
        string sNumber;
        
        int wordPointer = 0;
        for(int i = 0; i < abbr.size(); ++i)
        {
            //by default, we assume all zero we found is a leading zero.
            if(abbr[i] == '0' && leadingZero)
                return false;
            
            //if that is not the case, means we are not encountering leading zero or we are encountering non-zero.
            //in this case, we mark we do not have leading zero and start recording all numbers.
            if(abbr[i] >= '0' && abbr[i] <= '9')
            {
                leadingZero = false;
                sNumber += abbr[i];
                
                //if we are at end of the array, or the next element is not a number, it means that we finished recording and it is time to verify.
                if(sNumber.size() > 0 && (i + 1 >= abbr.size() || 
                   (!(abbr[i + 1] >= '0' && abbr[i + 1] <= '9'))))
                   {
                       //convert to int
                       int num = 0;
                       for(int i = 0; i < sNumber.size(); ++i)
                       {   
                           num *= 10;
                           num += sNumber[i] - 48;
                       }
                       sNumber = "";
                       wordPointer += num;
                       if(wordPointer > word.size())
                           return false;
                   }
            }
            else
            {
                if(word[wordPointer] != abbr[i])
                    return false;
                ++wordPointer;
            }
        
        }
        return wordPointer == word.size();
    }
};