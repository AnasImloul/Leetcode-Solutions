# Runtime: 1382 ms (Top 13.45%) | Memory: 15.1 MB (Top 9.94%)
class Solution:
    def largest1BorderedSquare(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        dp = [[[grid[i][j]] * 4 for j in range(n)] for i in range(m)]
        for i in range(m):
            for j in range(n):
                if i > 0:
                    if grid[i][j] == 1:
                        dp[i][j][1] = dp[i - 1][j][1] + 1
                if j > 0:
                    if grid[i][j] == 1:
                        dp[i][j][0] = dp[i][j - 1][0] + 1
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if i < m - 1:
                    if grid[i][j] == 1:
                        dp[i][j][2] = dp[i + 1][j][2] + 1
                if j < n - 1:
                    if grid[i][j] == 1:
                        dp[i][j][3] = dp[i][j + 1][3] + 1
        mside = min(m, n)
        for l in range(mside - 1, -1, -1):
            for i in range(m - l):
                for j in range(n - l):
                    if min(dp[i][j][2], dp[i][j][3], dp[i + l][j + l][0], dp[i + l][j + l][1]) >= l + 1:
                        return (l + 1) * (l + 1)
        return 0