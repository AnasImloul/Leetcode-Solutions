class Solution:
    def numMovesStones(self, a: int, b: int, c: int) -> List[int]:
        a,b,c = sorted([a,b,c])
        d1 = abs(b-a)-1 
        d2 = abs(c-b)-1
        mi = 2
        if d1 == 0 and d2 == 0: mi = 0
        elif d1 <= 1 or d2 <= 1: mi =1    
        ma = c - a - 2
        return [mi,ma]