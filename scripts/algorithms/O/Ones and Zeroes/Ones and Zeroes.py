# Runtime: 7928 ms (Top 10.31%) | Memory: 14.1 MB (Top 82.43%)
class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        dp = [[0 for _ in range(m+1)] for _ in range(n + 1)]
        for s in strs:
            zeroes = s.count("0")
            ones = len(s)-zeroes
            for i in range(n, ones-1, -1):
                for j in range(m, zeroes-1, -1):
                    dp[i][j] = max(dp[i][j], dp[i-ones][j-zeroes]+1)
        return dp[n][m]