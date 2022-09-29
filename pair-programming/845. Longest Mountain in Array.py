class Solution(object):
    def longestMountain(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        
        maxWidth = 0
        
        #0 = only accepts upwards
        #1 = only accepts upwards or downwards
        #2 = only accepts downwards
        state = 0 
        
        
        curWidth = 1
        i = 1
        
        reset = False
        while i < len(arr):
            
            if arr[i - 1] < arr[i] and ((state is 0) or (state is 1)):                
                #we do not compare or save to maxWidth because its not a vaild mountain yet.
                curWidth += 1
                print(str(i) + " inc " + str(curWidth))
                state = 1
                reset = False
            elif arr[i - 1] > arr[i] and ((state is 1) or (state is 2)):
                curWidth += 1
                print(str(i) + " dec " + str(curWidth))
                state = 2
                if(curWidth > maxWidth):
                    maxWidth = curWidth    
                reset = False
            else:
                print(str(i) + " reset")
                curWidth = 1
                state = 0    
                if reset is False:
                    i -= 1
                    reset = True
            i+=1
 
        return maxWidth
            
        
        
