class KthLargest(object):

    def __init__(self, k, nums):
        """
        :type k: int
        :type nums: List[int]
        """
        self.base = 10000
        self.k = k
        self.num_count = [0] * (2 * self.base + 1)
        self.k_largest = None
        
        
        for num in nums:
            self.num_count[num + self.base] += 1
    

    def add(self, val):
        """
        :type val: int
        :rtype: int
        """
        self.num_count[val + self.base] += 1
        
        if(self.k_largest is None):
            cnt = 0
            for i in range(len(self.num_count) - 1,0,-1):
                cnt += self.num_count[i]

                if(cnt >= self.k):
                    index = cnt - self.k
                    self.k_largest = [i - self.base,index]
                    return self.k_largest[0]
        
        if val > self.k_largest[0]:
            cur_index = self.k_largest[1] + 1
            old_largest = self.k_largest[0]
            for i in range(self.k_largest[0] + self.base, len(self.num_count) - 1):
                cur_num_count = self.num_count[i]
                if(cur_index < cur_num_count):
                    self.k_largest = [i - self.base, cur_index]
                    print(self.k_largest,val)
                    break
                else:
                    cur_index = 0          
        elif val == self.k_largest[0]:
            self.k_largest[1] += 1
        return self.k_largest[0]
        

        


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)
