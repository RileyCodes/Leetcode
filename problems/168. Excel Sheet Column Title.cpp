class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        string s;
        
        while(columnNumber)
        {
            --columnNumber;
            int index = (columnNumber % 26);
            s = (char)('A' + index) + s;
            columnNumber /= 26;
        }
        return s;
    }
};