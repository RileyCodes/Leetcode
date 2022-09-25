class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int slotCount = 0;
        
        for(int i = 0; i < flowerbed.size(); ++i)
        {
            if((i - 1 < 0 || flowerbed[i - 1] == 0)
              && (i + 1 >= flowerbed.size() || flowerbed[i + 1] == 0)
              && flowerbed[i] == 0)
            {
                ++slotCount;
                flowerbed[i] = 1;
            }
        }
        
        return n <= slotCount;
    }
};