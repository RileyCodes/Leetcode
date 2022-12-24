class Solution {
public:
    int numDecodings(string s) {
        int arr[s.size()], n = s.size();
        
        arr[n - 1] = s[n - 1] != '0'? 1 : 0;
        
        if(n == 1)
            return arr[n - 1];

        for(int i = n - 2;i >= 0; i--)
        {
            if(s[i] == '0')
                arr[i] = 0;
            else if(s[i + 1] > '6' && s[i] > '1' || s[i] > '2' )
            {
                 arr[i] = arr[i + 1];
            }
            else
                arr[i] = arr[i + 1] + (i == n - 2? 1 :arr[i + 2]);
        }
        
        return arr[0];
    }
};
