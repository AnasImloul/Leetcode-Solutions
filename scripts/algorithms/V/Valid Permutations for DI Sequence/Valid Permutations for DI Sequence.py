// Runtime: 46 ms (Top 80.0%) | Memory: 18.80 MB (Top 54.55%)

class Solution:
    def numPermsDISequence(self, s: str) -> int:
        n = len(s)
        dp = [[None for j in range(n-i+1)] for i in range(n)]
        for j in range(n-1, 0-1, -1):
            if s[j] == "I":
                if j == n-1:
                    dp[j][0] = 1
                    dp[j][1] = 0
                else:
                    dp[j][n-j] = 0
                    for i in range((n-j)-1, 0-1, -1):
                        dp[j][i] = dp[j+1][i]+dp[j][i+1]
            else:
                if j == n-1:
                    dp[j][0] = 0
                    dp[j][1] = 1
                else:
                    dp[j][0] = 0
                    for i in range(1, n-j+1):
                        dp[j][i] = dp[j+1][i-1]+dp[j][i-1]
        return sum([dp[0][i] for i in range(n+1)])%(10**9+7)
