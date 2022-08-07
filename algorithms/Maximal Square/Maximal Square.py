class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        m, n = len(matrix), len(matrix[-1])   
        dp = [[0] * n for _ in range(m)]     
        max_area = 0
        for i in range(m):
            for j in range(n): 
                if i - 1 < 0 or j - 1 < 0:
                    if matrix[i][j] == '1': dp[i][j] = 1
                else:
                    if matrix[i][j] == '1':
                        dp[i][j] = 1 + min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j])
                max_area = max(max_area, dp[i][j] ** 2)
        return max_area
