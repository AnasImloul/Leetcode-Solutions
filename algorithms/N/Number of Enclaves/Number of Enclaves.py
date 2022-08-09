class Solution:
    def recursion(self, grid, row, col, m, n):
        if 0<=row<m and 0<=col<n and grid[row][col] == 1:
            grid[row][col] = 't'
            self.recursion(grid, row+1, col, m, n)
            self.recursion(grid, row-1, col, m, n)
            self.recursion(grid, row, col+1, m, n)
            self.recursion(grid, row, col-1, m, n)
    
    def numEnclaves(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        if not m or not n:
            return 0
        # mark all boundary lands and neighbors with 0
        for row in range(m):
            self.recursion(grid, row, 0, m, n)
            self.recursion(grid, row, n-1, m, n)
            
        for col in range(n):
            self.recursion(grid, 0, col, m, m)
            self.recursion(grid, m-1, col, m, n)
        
        result = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    result += 1
        
        
        return result
