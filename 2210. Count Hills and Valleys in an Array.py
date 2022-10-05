class Solution(object):
    def countHillValley(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        #0 = up or down ok
        #1 = down only
        
        cnt = 0
        
        up = False
        down = False
        i = 1
        while(i < len(nums)):
            if(nums[i] > nums[i - 1]): #increasing
                up = True
            elif(nums[i] < nums[i - 1]): #decreasing
                down = True
            
            if up and down:
                cnt += 1
                state = []
                up = False
                down = False
                i -= 1
            i += 1
                
        return cnt
                
            
        
