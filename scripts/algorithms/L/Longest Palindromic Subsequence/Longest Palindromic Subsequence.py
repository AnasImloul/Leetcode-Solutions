// Runtime: 1248 ms (Top 52.16%) | Memory: 34.60 MB (Top 50.8%)

class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        dp = [[0 for _ in range(len(s))] for _ in range(len(s))]
        for k in range(1, len(s) + 1):
            for i in range(len(s) - k + 1):
                j = k + i - 1
                if i == j:
                    dp[i][j] = 1
                elif i + 1 == j and s[i] == s[j]:
                    dp[i][j] = 2
                elif s[i] == s[j]:
                    dp[i][j] = dp[i+1][j-1] + 2
                else:
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1])
        return dp[0][-1]
