class Solution {
public:



    int totalFruit(vector<int>& fruits) {

        unordered_map<int,int> baskets;
        int maxWidth = 0;

        int j = 0;
        for(int i = 0; i < fruits.size(); ++i)
        {
            while(j  < fruits.size() && 
              (baskets.count(fruits[j]) ||
            baskets.size() <= 1))
            {
                ++baskets[fruits[j]];
                ++j;                    
            }

            maxWidth = max(maxWidth, j - i);
            --baskets[fruits[i]];
            if(baskets[fruits[i]] == 0)
                baskets.erase(fruits[i]);
        }



        return maxWidth;
    }
};