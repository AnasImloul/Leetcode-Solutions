class Solution:
    def maximumSwap(self, num: int) -> int:
        digits = [int(x) for x in str(num)]
        n = len(digits)
        
        for i in range(n):
            maxx = digits[i]
            indx = i
            
            for j in range(i+1,n):
                if digits[j]>=maxx and digits[j]!=digits[i]:
                    maxx = digits[j]
                    indx = j
                                        
            if indx!=i:
                digits[i],digits[indx] = digits[indx],digits[i]
                    
                #only one swap allowed
                return "".join([str(x) for x in digits])
                
        #already sorted
        return num
