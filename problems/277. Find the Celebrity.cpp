/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int cur = 0;
        int min = 1;

        while(true)
        {
            if(min >= n)
                break;
            //cout << cur << " " << min << endl;
            int aKnowsB = knows(cur, min);
            int bKnowsA = knows(min, cur);
            if(aKnowsB)
            {
                cur = min;
                ++min;
            }
            else if(bKnowsA)
            {
                ++min;
            }
            else 
            {
                cur = min + 1;
                min = min + 2;
            }
        }
        
        if(cur >= n)
            return -1;
        
        for(int i = 0; i < n; ++i)
        {
            //cout << cur << " " << i << endl;
            if(i != cur && (knows(cur, i) || !knows(i, cur)))
                return -1;
                
        }
        return cur;
    }
};