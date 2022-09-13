# Runtime: 1687 ms (Top 8.20%) | Memory: 16.3 MB (Top 73.07%)
class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:

        m = len(matrix)
        n = len(matrix[0])

        dp = [[0 for _ in range(n)] for _ in range(m)]
        total = 0

        for i in range(m):
            for j in range(n):

                if i == 0:
                    dp[i][j] = matrix[0][j]

                elif j == 0:
                    dp[i][j] = matrix[i][0]

                else:
                    if matrix[i][j] == 1:
                        dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j-1], dp[i-1][j])

                total += dp[i][j]

        return total