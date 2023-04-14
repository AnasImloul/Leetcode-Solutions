class Solution:
    def findValidSplit(self, nums: List[int]) -> int:
        def PF(n): #O(sqrt(n))
                while (n%2 == 0) :
                    yield 2
                    n = n/2; 
                for i in range(3,int(sqrt(n))+1,2):
                    while (n%i == 0) :
                        yield i
                        n = n/i; 
                if (n > 2) : yield n
                
        def checkCounter(): 
            for k in b.keys() : # we know that b contains all the keys :)
                if a[k] and b[k] : return 0
            return 1
            
        b=Counter()
        for n in nums : #O(n)
            for f in PF(n): 
                b[f]+=1
        a=Counter()
        for i in range (len(nums)-1): #O(n)
            # updating the counter
            for f in PF(nums[i]):
                a[f]+=1
                b[f]-=1
            if checkCounter(): return i 
        else : return -1