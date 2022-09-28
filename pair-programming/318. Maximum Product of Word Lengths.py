class Solution(object):

    #approach 1, using set
    def maxProduct(self, words):
        result = 0
        mapping = {word: set(word) for word in words}

        for i in range(len(words)):
            for j in range(i + 1, len(words)):
                if (len(words[i]) * len(words[j])) <= result:
                    continue
                    
                skip = False
                for chr in mapping[words[i]]:
                    if(chr in mapping[words[j]]):
                        #print(words[i] + ' ' + words[j])
                        skip = True
                        break;
                if not skip:
                    result = max(result, len(words[i]) * len(words[j]))
        return result
  
    #approach2 using binwise operation
    def maxProduct(self, words):
        d = {}
        for w in words:
            mask = 0
            for c in set(w):
                
                # we push 1 to the left by the index of chatacter in alphabet( a = 0, b = 1)
                # and we use |= to keep the previous states
                # for example, a will have a mask of 1, ac will have a mask of 101
                # in this way, we got a mask that represents whether a unique character was used in word
                mask |= (1 << (ord(c) - 97))
                
            #Use the mask as the key and store the maximum length of words we found with the same usage of unique characters. 
            
            d[mask] = max(d.get(mask, 0), len(w))
            #print(str(bin(mask)) + " " + str(bin(d[mask])) + " " + str(d[mask]))         
            
        # "not x & y" insures we skip all combination that shares same unique chatacter
        #For example, ac = 101, bc = 110. 101 & 110 != 0 so it will be omitted.
        #ab = 0011 and cd = 1100 , 1100 & 0011 == 0 so it will be calculated if its the max product we can find.
        return max([d[x] * d[y] for x in d for y in d if not x & y] or [0])
