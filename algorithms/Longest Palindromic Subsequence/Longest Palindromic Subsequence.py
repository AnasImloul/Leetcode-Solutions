class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        n = len(s)
        dp = [[0 for x in range(n)] for x in range(n)]
        for i in range(n): dp[i][i] = 1 # Single length strings are palindrome
        for chainLength in range(2, n+1):
            for i in range(0, n-chainLength+1): # Discarding the lower triangle
                j = i + chainLength - 1
                if s[i] == s[j]: 
                    if chainLength == 2: dp[i][j] = 2
                    else: dp[i][j] = dp[i+1][j-1] + 2
                else: dp[i][j] = max(dp[i+1][j], dp[i][j-1])
        return dp[0][n-1]
