class Solution:
    def minMoves(self, target: int, maxDoubles: int) -> int:
        c=0
        while(maxDoubles>0 and target>1):
            c += target%2
            target //= 2
            c += 1
            maxDoubles -=1
        return c + target-1