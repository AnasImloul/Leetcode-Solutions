class Solution:
    def maxCount(self, m: int, n: int, ops: List[List[int]]) -> int:
        if not ops:
            return m*n
        else:
            x,y = zip(*ops)
            return min(x) * min(y)
