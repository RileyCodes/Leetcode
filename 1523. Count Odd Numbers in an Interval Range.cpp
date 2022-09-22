class Solution {
public:
    /*
    1 2 3 4 5 6 7 8 9
    if we pick 1 [2 3 4 5 6 7 8 9]
    9 - 2 = 7
    odd: 3 5 7 9 , we have (7 / 2) + 1 of odd numbers.
    
    if we pick [1 2 3 4 5 6 7 8] 9
    8 - 1 = 7
    odd are: 1 3 5 7, it's still (7 / 2) + 1 of odd numbers.
    
    if we pick 1 [2 3 4 5 6 7 8] 9
    8 - 2 = 6
    odd are: 3 5 7, but (6 / 2) + 1 = 4 insted of 3.
    
    It seems like if the range is even , we will have range / 2
    if the range is odd, we will have range / 2 + 1
    2 3 4 5 6
    5 /2 = 2,  2 + 1 =3, but only odd number is 3 and 5
    3 4 5 6 7 would be ok, we have odd numbers of 3 5 7
    
    ok, if the range is even, we will always have same amount of odd and even numbers.
    if the range is odd, we might face two cases: [1,2,3,4,5] - 3 odd or [2,3,4,5,6] - 2 odd
    */

    int countOdds(int low, int high) {
        int range = high - low +  1;
        if(range % 2 == 0)
            return range / 2;
        
        if(low % 2 == 0)
            return range / 2;
        
        return range / 2 + 1;
    }
};