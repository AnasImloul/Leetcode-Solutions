class Solution:
    def concatenatedBinary(self, n: int) -> int:
        modulo = 10 ** 9 + 7
        shift = 0 # tracking power of 2
        res = 0
        
        for i in range(1, n+1):
            if i & (i - 1) == 0: # see if num reaches a greater power of 2
                shift += 1
            res = ((res << shift) + i) % modulo # do the simulation
        
        return res