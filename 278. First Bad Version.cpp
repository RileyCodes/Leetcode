
class Solution {
public:
    int firstBadVersion(int n) {
        int lBound = 1, rBound = n;
        while(rBound - lBound >= 0)
        {
            int mid = ((rBound - lBound) / 2) + lBound;
            if(isBadVersion(mid))
                rBound = mid - 1;        
            else
                lBound = mid + 1;
        }
        if(rBound < lBound)
            return lBound;
        return rBound;
    }
};