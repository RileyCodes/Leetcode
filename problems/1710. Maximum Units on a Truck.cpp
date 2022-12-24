class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        //since I dont know how to sort vector by 2nd element, lets re-orginaze it a bit.
        for(int i = 0; i < boxTypes.size(); ++i)
        {
            swap(boxTypes[i][0],boxTypes[i][1]);
        }
        
        sort(boxTypes.begin(),boxTypes.end(),std::greater());
        
        
        int units = 0;
        for(int i = 0; i < boxTypes.size(); ++i)
        {
            units += min(truckSize,boxTypes[i][1]) * boxTypes[i][0];
            
            truckSize -= boxTypes[i][1];
            if(truckSize <= 0)
                break;
        }
        return units;
    }
};