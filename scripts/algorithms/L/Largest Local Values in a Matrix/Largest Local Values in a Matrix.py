# Runtime: 152 ms (Top 51.5%) | Memory: 16.74 MB (Top 93.8%)

class Solution:
    def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:
        n = len(grid)
        ans = [[0]*(n-2) for _ in range(n-2)]
        for i in range(n-2): 
            for j in range(n-2): 
                ans[i][j] = max(grid[ii][jj] for ii in range(i, i+3) for jj in range(j, j+3))
        return ans 