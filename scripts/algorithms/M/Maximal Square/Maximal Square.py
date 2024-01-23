// Runtime: 499 ms (Top 97.16%) | Memory: 19.30 MB (Top 88.93%)

class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        m, n = len(matrix), len(matrix[0])
        result = 0
        dp = [[0]*n for _ in range(m)]  # dp[x][y] is the length of the maximal square at (x, y)
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == '1':  # ensure this condition first
                    # perform computation, mind border restrictions
                    dp[i][j] = min(dp[i-1][j] if i > 0 else 0,
                                   dp[i][j-1] if j > 0 else 0,
                                   dp[i-1][j-1] if i > 0 and j > 0 else 0) + 1
                    if dp[i][j] > result:
                        result = dp[i][j]
        return result*result
