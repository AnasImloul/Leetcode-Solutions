from functools import lru_cache
class Solution:
    def countPaths(self, grid: List[List[int]]) -> int:
        
        
        row = len(grid)
        col = len(grid[0])
        
        @lru_cache(None)
        def helper(i, j):
            
            drs = [(-1,0),(1,0),(0,-1),(0,1)]
            t = 0
            for x,y in drs:
                if  0 <= i+x < row and 0 <= j+y < col and grid[i+x][j+y] > grid[i][j]:
                    t += 1+helper(i+x, j+y)
            return t
                    

        
        m = (10**9) + 7
        ans = row*col%m
        
        for i in range(row):
            for j in range(col):
                ans += helper(i, j)%m
                ans %= m
                
                
        return ans
