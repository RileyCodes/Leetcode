class OrderedStream(object):

    def __init__(self, n):
        """
        :type n: int
        """
        self.lst = [None] * n
        self.pointer = 0
        

    def insert(self, idKey, value):
        """
        :type idKey: int
        :type value: str
        :rtype: List[str]
        """
        ans = []
        self.lst[idKey - 1] = value
        while(self.pointer < len(self.lst) and self.lst[self.pointer] is not None):
            ans.append(self.lst[self.pointer])
            self.pointer += 1
        return ans;
        


# Your OrderedStream object will be instantiated and called as such:
# obj = OrderedStream(n)
# param_1 = obj.insert(idKey,value)