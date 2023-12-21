// Runtime: 1143 ms (Top 75.31%) | Memory: 238.70 MB (Top 9.88%)

class Solution:
    def hasValidPath(self, grid: List[List[str]]) -> bool:  
        m = len(grid)
        n = len(grid[0])
        @lru_cache(maxsize=None)
        def hasValidPathInner(x, y, cnt):
            # cnt variable would act as a counter to track 
            # the balance of parantheses sequence
            if x == m or y == n or cnt < 0:
                return False
            
            # logic to check the balance of sequence
            cnt += 1 if grid[x][y] == '(' else -1
            
            # if balanced and end of grid, return True
            if x == m - 1 and y == n - 1 and not cnt:
                return True
            
            return hasValidPathInner(x + 1, y, cnt) or hasValidPathInner(x, y + 1, cnt)

        return hasValidPathInner(0, 0, 0)
