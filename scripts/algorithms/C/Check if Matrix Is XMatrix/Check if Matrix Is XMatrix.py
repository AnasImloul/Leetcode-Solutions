// Runtime: 215 ms (Top 99.74%) | Memory: 18.30 MB (Top 16.93%)

class Solution:
    def checkXMatrix(self, grid: List[List[int]]) -> bool:
        n = len(grid)
        for i in range(n):
            for j in range(n):
                if i==j or (i+j) ==n-1:
                    if grid[i][j] == 0:
                        return False
                elif grid[i][j] != 0: 
                    return False
        return True;
