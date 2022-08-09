import numpy as np

class Solution:
    def maxTrailingZeros(self, grid: List[List[int]]) -> int:
        A = np.array(grid)
        def cumdivs(d):
            D = sum(A % d**i == 0 for i in range(1, 10))
            return D.cumsum(0) + D.cumsum(1) - D
        return max(np.minimum(cumdivs(2), cumdivs(5)).max()
                   for _ in range(4)
                   if [A := np.rot90(A)])
