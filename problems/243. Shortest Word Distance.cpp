class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        
        int word1Index = -1;
        int word2Index= -1;
        
        int minWidth = INT_MAX;
        for(int i = 0; i < wordsDict.size(); ++i)
        {
            if(wordsDict[i] == word1)
            {
                word1Index = i;
            }
            else if(wordsDict[i] == word2)
            {
                word2Index = i;
            }
            if(word1Index != -1 && word2Index != -1)
            {
                minWidth = min(minWidth,abs(word2Index - word1Index));
            }
        }
        return minWidth;
    }
};