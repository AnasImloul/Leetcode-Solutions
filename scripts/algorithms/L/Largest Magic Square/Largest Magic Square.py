# Runtime: 1987 ms (Top 15.7%) | Memory: 16.60 MB (Top 82.4%)

class Solution:
    def largestMagicSquare(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0]) # dimensions 
        rows = [[0]*(n+1) for _ in range(m)] # prefix sum along row
        cols = [[0]*n for _ in range(m+1)] # prefix sum along column
        
        for i in range(m):
            for j in range(n): 
                rows[i][j+1] = grid[i][j] + rows[i][j]
                cols[i+1][j] = grid[i][j] + cols[i][j]
        
        ans = 1
        for i in range(m): 
            for j in range(n): 
                diag = grid[i][j]
                for k in range(min(i, j)): 
                    ii, jj = i-k-1, j-k-1
                    diag += grid[ii][jj]
                    ss = {diag}
                    for r in range(ii, i+1): ss.add(rows[r][j+1] - rows[r][jj])
                    for c in range(jj, j+1): ss.add(cols[i+1][c] - cols[ii][c])
                    ss.add(sum(grid[ii+kk][j-kk] for kk in range(k+2))) # anti-diagonal
                    if len(ss) == 1: ans = max(ans, k+2)
        return ans 