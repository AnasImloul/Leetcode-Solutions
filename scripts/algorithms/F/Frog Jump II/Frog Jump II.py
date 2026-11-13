# Runtime: 53 ms (Top 15.85%) | Memory: 35.90 MB (Top 88.68%)

class Solution:
    def maxJump(self, stones: List[int]) -> int:
        if len(stones) == 2:
            return (stones[-1] - stones[0])
        maxjump = 0
        i, j = 0, 2
        while j < len(stones):
            maxjump = max(maxjump, (stones[j] - stones[i]))
            i+= 1; j+= 1
        return maxjump
