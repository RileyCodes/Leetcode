class Solution(object):
    def shipWithinDays(self, weights, days):
        """
        :type weights: List[int]
        :type days: int
        :rtype: int
        """
        minCapacity = max(weights)
        maxCapacity = reduce(lambda a, b: a+b, weights) + 1
        
        ans = sys.maxint
        while minCapacity <= maxCapacity:
            mid = (minCapacity + maxCapacity) / 2
            
            print(minCapacity, maxCapacity,mid)
            def days_required(capacity):
                actual_days = 0
                cur_weight = 0
                index = 0
                while index < len(weights):
                    while index < len(weights) and cur_weight + weights[index] <= capacity:
                        cur_weight += weights[index]
                        index += 1
                    actual_days += 1
                    cur_weight = 0     
                return actual_days
                        
            actual_days = days_required(mid)
            

            if actual_days > days:
                minCapacity = mid + 1
            elif actual_days <= days:
                ans = ans if ans < mid else mid
                maxCapacity = mid - 1

                
        return ans