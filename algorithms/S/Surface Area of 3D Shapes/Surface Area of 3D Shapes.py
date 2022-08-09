class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        ans = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if i == 0:
                    ans += grid[i][j]
                if i == len(grid) - 1:
                    ans += grid[i][j]
                if j == 0:
                    ans += grid[i][j]
                if j == len(grid[0]) - 1:
                    ans += grid[i][j]
                if i < len(grid) - 1:
                    ans += abs(grid[i + 1][j] - grid[i][j])
                if j < len(grid[0]) - 1:
                    ans += abs(grid[i][j + 1] - grid[i][j])
                if grid[i][j] > 0:
                    ans += 2
        return ans
