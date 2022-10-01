class Solution(object):
    def maximumProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        pos = [x for x in nums if x > 0]
        neg_and_zero = [x for x in nums if x <= 0]
        
        pos.sort();
        neg_and_zero.sort();
        
        results = [];
        if(len(pos) >= 3):
            results.append(pos[-1] * pos[-2] * pos[-3])
        if len(neg_and_zero) >= 2 and len(pos) >= 1:
            results.append(pos[-1] * neg_and_zero[0] * neg_and_zero[1])
        if len(neg_and_zero) >= 3:
            results.append(neg_and_zero[-1] * neg_and_zero[-2] * neg_and_zero[-3])
        if len(neg_and_zero) >= 1 and len(pos) >= 2:
            results.append(neg_and_zero[-1] * pos[0] * pos[1])
            
        results.sort();
        return results[-1]
        
        
        