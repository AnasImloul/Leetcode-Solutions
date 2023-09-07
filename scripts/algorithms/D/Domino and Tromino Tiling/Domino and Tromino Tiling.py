# Runtime: 35 ms (Top 93.5%) | Memory: 16.27 MB (Top 85.2%)

class Solution(object):
    def numTilings(self, n):
        dp = [1, 2, 5] + [0] * n
        for i in range(3, n):
            dp[i] = (dp[i - 1] * 2 + dp[i - 3]) % 1000000007
        return dp[n - 1]