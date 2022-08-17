class Solution:
    def minFallingPathSum(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        if m == 1 and n == 1:
            return grid[0][0]
        min_arr = [0 for _ in range(n)]
        for i in range(m):
            prefix = [float('inf') for _ in range(n)]
            suffix = [float('inf') for _ in range(n)]
            current_row = [elem1+elem2 for elem1, elem2 in zip(grid[i], min_arr)]
            for i in range(1, n):
                prefix[i] = min(prefix[i-1], current_row[i-1])
            for i in range(n-2, -1, -1):
                suffix[i] = min(suffix[i+1], current_row[i+1])
            min_arr = [min(pre, suff) for pre, suff in zip(prefix, suffix)]
        return min(min_arr)
