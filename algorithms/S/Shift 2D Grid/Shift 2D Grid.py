class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        cache = []
        for i in range(m):
            for j in range(n):
                cache.append(grid[i][j])
        
        k %= len(cache)
        new_vals = cache[-k:] + cache[:-k]
        
        cur = 0
        for i in range(m):
            for j in range(n):
                grid[i][j] = new_vals[cur]
                cur += 1
        
        return grid
