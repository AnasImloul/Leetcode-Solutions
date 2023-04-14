class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        n = len(grid)
        Rows_max = {}
        Cols_max = {}
        for i in range(n):
            Rows_max[i] = max(grid[i])
            Max = 0
            for j in range(n):
                Max = max(grid[j][i], Max)
            
            Cols_max[i] = Max


        count = 0
        for r in range(n):
            for c in range(n):
                if grid[r][c] == Rows_max[r] or grid[r][c] == Cols_max[c]:
                    continue
                
                height_to_add = min(Rows_max[r], Cols_max[c])
                count += height_to_add - grid[r][c]
                
        return count
            
        