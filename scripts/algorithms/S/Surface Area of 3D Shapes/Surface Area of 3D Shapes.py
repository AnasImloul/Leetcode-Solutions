class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:        
        m, n = len(grid), len(grid[0])
        
        area = 0
        for r in range(m):               
            for c in range(n):
                if grid[r][c] != 0:
                    area += 2
                
                if r == 0 or r == m - 1:
                    area += grid[r][c] if m != 1 else 2*grid[r][c]
                if r != m - 1:                    
                    area += abs(grid[r][c] - grid[r+1][c])
                    
                if c == 0 or c == n - 1:
                    area += grid[r][c] if n != 1 else 2*grid[r][c]
                if c != n - 1:                    
                    area += abs(grid[r][c] - grid[r][c+1])                    
                
        return area