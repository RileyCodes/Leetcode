class Solution(object):
    def maximumPopulation(self, logs):
        """
        :type logs: List[List[int]]
        :rtype: int
        """
        
        base = 1950
        h = [0] * 101
        for log in logs:
            h[log[0] - base] +=1;
            h[log[1] - base] -=1;
            
        cnt = 0
        maximum = [0,1950]
        for index, chg in enumerate(h):
            cnt += chg
            if cnt > maximum[0]:
                maximum = [cnt,index + base]
                
        return maximum[1]
