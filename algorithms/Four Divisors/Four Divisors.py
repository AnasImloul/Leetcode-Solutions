import math 
class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        s=0
        for i in nums:
            r=i+1
            c=2
            for j in range(2, int(math.sqrt(i))+1):
                if i%j==0:
                    if (i / j == j) :
                        c+=1
                        r+=j
                    else :
                        c+=2
                        r+=j+int(i/j)
            print(c, r)
            if c==4:
                s+=r
        return s
