# Runtime: 75 ms (Top 36.49%) | Memory: 14 MB (Top 43.32%)
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        def valid(r,c,matrix):
            return r >= 0 and c >= 0 and r < len(matrix) and c < len(matrix[0])

        dp = [[0] * len(obstacleGrid[0]) for _ in range(len(obstacleGrid))]
        dp[0][0] = 1 ^ obstacleGrid[0][0]

        for r in range(len(obstacleGrid)):
            for c in range(len(obstacleGrid[0])):
                if obstacleGrid[r][c] != 1:
                    if valid(r-1, c, dp) and obstacleGrid[r-1][c] != 1:
                        dp[r][c] += dp[r-1][c]
                    if valid(r, c-1, dp) and obstacleGrid[r][c-1] != 1:
                        dp[r][c] += dp[r][c-1]

        return dp[-1][-1]