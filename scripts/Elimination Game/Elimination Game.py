class Solution:
    def lastRemaining(self, n: int) -> int:
        beg = 1
        len = n
        d = 1
        fromleft = True

        while len > 1:
            if(fromleft or len%2 == 1):
                beg += d
            d <<= 1
            len >>= 1
            fromleft = not fromleft
        
        return beg
