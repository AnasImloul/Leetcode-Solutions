# Runtime: 4 ms (Top 46.43%) | Memory: 19.90 MB (Top 59.69%)

class Solution:
    def findChampion(self, grid: List[List[int]]) -> int:

        n = len(grid)

        for i in range(n):
            if sum(grid[i]) == n - 1:
                return i
