class Solution(object):
    def maxIncreaseKeepingSkyline(self, grid):
        rows = cols = len(grid)
        maxRows, maxCols = [0]*rows, [0]*cols
        ans = 0
        
        for i in range(rows):
            for j in range(cols):
                maxRows[i] = max(grid[i][j], maxRows[i])
                maxCols[j] = max(grid[i][j], maxCols[j])
                
        for r in range(rows):
            for c in range(cols):
                ans += min(maxRows[r], maxCols[c]) - grid[r][c]
                
        return ans
