class Solution:
    def numTimesAllBlue(self, flips: List[int]) -> int:
        
        
        l = len(flips)
        s = 0
        c = 0
        
        for i in range(len(flips)):
            f = flips[i]
            s = 1 << (f - 1) | s
            if s ==  (1 << (i+1))-1:
                c += 1
        
        return c
