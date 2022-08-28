// Runtime: 28 ms (Top 98.15%) | Memory: 13.9 MB (Top 68.10%)
class Solution:
    def countVowelStrings(self, n: int) -> int:
        dp = [[0] * 6 for _ in range(n+1)]
        for i in range(1, 6):
            dp[1][i] = i

        for i in range(2, n+1):
            dp[i][1]=1
            for j in range(2, 6):
                dp[i][j] = dp[i][j-1] + dp[i-1][j]

        return dp[n][5]