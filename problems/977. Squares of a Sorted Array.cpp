class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int firstIndex = 0, lastIndex = nums.size() - 1;
        int currentIndex = lastIndex;
        vector<int> result(nums.size());
        while(firstIndex != lastIndex)
        {
            int squareFirst = nums[firstIndex] * nums[firstIndex];
            int squareLast = nums[lastIndex] * nums[lastIndex];
            if(squareFirst > squareLast)
            {
                result[currentIndex--]  = squareFirst;
                firstIndex++;
            }
            else
            {
                result[currentIndex--]  = squareLast;
                lastIndex--;   
            }
        }
        result[currentIndex--]  = nums[firstIndex] * nums[firstIndex];
        return result;
    }
};