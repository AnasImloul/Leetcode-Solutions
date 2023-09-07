# Runtime: 382 ms (Top 98.7%) | Memory: 16.57 MB (Top 93.9%)

class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        perimeter = 0

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    perimeter += 4
                    if i != 0 and grid[i-1][j] == 1:
                        perimeter -= 2
                    if j != 0 and grid[i][j-1] == 1:
                        perimeter -= 2 
            
        return perimeter
