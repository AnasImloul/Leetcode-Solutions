class Solution:
    def countPyramids(self, grid):      
        # dp[i][j] represents the number of layers of the largest pyramid with (i, j) as the vertex.
        # Note that the 1-level pyramid is invalid in the problem, so it should be removed when summing.
        # Note that if grid[i][j] is 0, dp[i][j] will always be 0.
        # The dp recurrence formula is dp[i][j] = min(dp[i + 1][j - 1], dp[i + 1][j + 1]) + 1
        m, n, dp, cnt = len(grid), len(grid[0]), copy.deepcopy(grid), 0
        # triangle
        for i in range(m - 2, -1, -1):
            for j in range(1, n - 1):
                if dp[i][j] > 0 and dp[i + 1][j] > 0:
                    dp[i][j] = min(dp[i + 1][j - 1], dp[i + 1][j + 1]) + 1
                    cnt += dp[i][j] - 1
        # inverted triangle
        dp = grid
        for i in range(1, m):
            for j in range(1, n - 1):
                if dp[i][j] > 0 and dp[i - 1][j] > 0:
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j + 1]) + 1
                    cnt += dp[i][j] - 1
        return cnt
