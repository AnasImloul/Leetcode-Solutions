// Runtime: 39 ms (Top 53.95%) | Memory: 17.30 MB (Top 9.72%)

class Solution:
    def uniquePaths(self, m, n):
        dp = [[1]*n for i in range(m)]
        for i, j in product(range(1, m), range(1, n)):
            dp[i][j] = dp[i-1][j] + dp[i][j-1]
        return dp[-1][-1]
