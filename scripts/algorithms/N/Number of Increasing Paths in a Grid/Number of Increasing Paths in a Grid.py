# Runtime: 2506 ms (Top 21.4%) | Memory: 118.67 MB (Top 7.1%)

class Solution:
    def __init__(self):
        self.dp = None
        self.di = [0, 0, -1, 1]
        self.dj = [-1, 1, 0, 0]
        self.mod = 1000000007
    
    def countPaths(self, grid):
        n = len(grid)
        m = len(grid[0])
        self.dp = [[0] * m for _ in range(n)]
        ans = 0
        for i in range(n):
            for j in range(m):
                ans = (ans + self.dfs(grid, i, j, -1)) % self.mod
        return ans
    
    def dfs(self, grid, i, j, prev):
        if i < 0 or j < 0 or i >= len(grid) or j >= len(grid[0]) or grid[i][j] <= prev:
            return 0
        if self.dp[i][j] != 0:
            return self.dp[i][j]
        self.dp[i][j] = 1
        for k in range(4):
            self.dp[i][j] += self.dfs(grid, i + self.di[k], j + self.dj[k], grid[i][j])
            self.dp[i][j] %= self.mod
        return self.dp[i][j] % self.mod
