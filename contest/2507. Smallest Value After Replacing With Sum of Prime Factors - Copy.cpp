class Solution {
public:
    
    bool isPrime(int n)
    {

      if(n==1||n==0) return false;
      for(int i=2; i*i<=n; i++)
      {
            if(n%i==0) return false;
      }

      return true;
    }
    
    int smallestValue(int n) {
        
        int ori = n;
        const int mag = 100000;
        static vector<int> primeNums;
        
        if(primeNums.size() == 0)
        {
            for(int i = 2; i <= mag; ++i)
            {
                if(isPrime(i))
                    primeNums.emplace_back(i);
            }            
        }

        
        vector<int> primeNumUsed;
        int primeNumCount = 0;
        
        int testingIndex = 0;
        while(1)
        {   
            if(primeNums[testingIndex] > ori) 
                return ori;
            
            if(n % primeNums[testingIndex] == 0)
            {
                primeNumCount +=  primeNums[testingIndex];
                n /= primeNums[testingIndex];


                if(n <= 1)
                    break;
                testingIndex = -1;
            }

            ++testingIndex;
        }
        
        int res = min(ori,primeNumCount);
        if(res == ori)
            return res;
        if(res <= 3)
            return res;
        return smallestValue(res);
    }
};