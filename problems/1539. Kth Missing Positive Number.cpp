class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int lastNum = 0;
        
        int totalMissingNum = 0;
        int lastMissingNum = 0;
        
        for(int num : arr)
        {
            //Ex: 1 - 0 - 1 = 0 missing number
            //2 - 1 - 1 = 0 missing number
            //3 - 1 - 1 = 1 missing number
            //4 - 1 - 1 = 2 missing numbers
            
            int missingNumCount = num - lastNum - 1;
            cout << missingNumCount << endl;
            totalMissingNum += missingNumCount;
            
            //if we found 3 more missing numbers ex: between 3 and 7, which is 4,5,6
            //we will just record the last missing number 6, which will be 7 - 1 = 6
            lastMissingNum = num - 1;
            
            
            
            if(totalMissingNum >= k)
            {
                /*if we have total of 5 missing numbers [1,2,4,5,6]
                and we only need 3rd missing numbers
                it means we need omit last two elements, 5 and 6.
                since 6 is at index of size() - 1, to omit 5 and 6 we will have (size() - 1) - (size() - k)
                but since we dont actually have an array, we can just use 6 - (5 - 3) = 6 - 2 = 4.
                
                we assumed that the numbersin "array" from [k,totalMissingNum] is continues. 
                the only possibile sccnoeino when its not coniutes is that we had numbets existed between two missing number intvals. but once we find K the program is done, there are no reason for this to happen.
                */
                
                
                return lastMissingNum - (totalMissingNum - k);
            }
            
            lastNum = num;
        }
        
        //in events there are not enough missing numbers, we will need go beyond the rightmost element in array
        
        //Ex: if we already found 3 missing numbers but we need 5th missing numbers, and the last element at array was 8
        //we will need (5 - 3) = 2 more missing numbers, and the kth missing numbers would be 8 + 2 = 10;
        k = k - totalMissingNum;
        return arr[arr.size() - 1] + k;
    }
};