// Runtime: 609 ms (Top 95.65%) | Memory: 24.30 MB (Top 75.94%)

class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        
        dp = [[[0]*(cols + 2) for _ in range(cols + 2)] for _ in range(rows + 1)]
        
        def get_next_max(row, col_r1, col_r2):
            res = 0
            for next_col_r1 in (col_r1 - 1, col_r1, col_r1 + 1):
                for next_col_r2 in (col_r2 - 1, col_r2, col_r2 + 1):
                    res = max(res, dp[row + 1][next_col_r1 + 1][next_col_r2 + 1])

            return res
        
        for row in reversed(range(rows)):
            for col_r1 in range(min(cols, row + 2)):
                for col_r2 in range(max(0, cols - row - 1), cols):

                    reward = grid[row][col_r1] + grid[row][col_r2]
                    if col_r1 == col_r2:
                        reward /= 2
                    
                    dp[row][col_r1 + 1][col_r2 + 1] = reward + get_next_max(row, col_r1, col_r2)
                    
        return dp[0][1][cols]
