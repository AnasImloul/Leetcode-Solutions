// Runtime: 94 ms (Top 84.44%) | Memory: 17.90 MB (Top 8.02%)

class DSU(object):
    def __init__(self, N):
        self.par = list(range(N))
        self.rnk = [0] * N

    def find(self, x):
        if self.par[x] != x:
            self.par[x] = self.find(self.par[x])
        return self.par[x]

    def union(self, x, y):
        xr, yr = self.find(x), self.find(y)
        if xr == yr:
            return False
        elif self.rnk[xr] < self.rnk[yr]:
            self.par[xr] = yr
        elif self.rnk[xr] > self.rnk[yr]:
            self.par[yr] = xr
        else:
            self.par[yr] = xr
            self.rnk[xr] += 1
        return True

class Solution:
    def swimInWater(self, grid):
        d, N = {}, len(grid)
        for i,j in product(range(N), range(N)):
            d[grid[i][j]] = (i, j)
        
        dsu = DSU(N*N)
        grid = [[0] * N for _ in range(N)] 
        neib_list = [[0,1],[0,-1],[1,0],[-1,0]]
        
        for i in range(N*N):
            x, y = d[i]
            grid[x][y] = 1
            for dx, dy in neib_list:
                if N>x+dx>=0 and N>y+dy>=0 and grid[x+dx][y+dy] == 1:
                    dsu.union((x+dx)*N + y + dy, x*N + y)
                    
            if dsu.find(0) == dsu.find(N*N-1): return i
