# Runtime: 210 ms (Top 11.28%) | Memory: 58.20 MB (Top 12.82%)

class Solution:
    def onesMinusZeros(self, grid: List[List[int]]) -> List[List[int]]:
        m = len(grid)
        n = len(grid[0])

        rows = {}
        for r in range(m):        
            row_sum = 0
            for c in range(n):
                row_sum += grid[r][c]

            rows[r] = row_sum

        cols = {}
        for c in range(n):
            col_sum = 0
            for r in range(m):
                col_sum += grid[r][c]

            cols[c] = col_sum

        res = [[0] * n for _ in range(m)]

        for r in range(m):
            for c in range(n):
                res[r][c] = rows[r] + cols[c] - (m - rows[r]) - (n - cols[c])

        return res
