# Runtime: 3008 ms (Top 6.15%) | Memory: 19.20 MB (Top 87.69%)

class Solution:
    def numberOfSets(self, n: int, maxDistance: int, roads: List[List[int]]) -> int:
        ans = 0
        for i in range(1 << n):
            g = [[float('inf')] * n for _ in range(n)]

            for x, y, w in roads:
                if ((i >> x) & 1) and ((i >> y) & 1):
                    g[x][y] = min(g[x][y], w)
                    g[y][x] = min(g[y][x], w)

            for j in range(n):
                g[j][j] = 0

            for p in range(n):
                for q in range(n):
                    for k in range(n):
                        g[q][k] = min(g[q][k], g[q][p] + g[p][k])

            ok = 1
            for j in range(n):
                for k in range(n):
                    if ((i >> j) & 1) and ((i >> k) & 1):
                        ok &= 1 if g[j][k] <= maxDistance else 0

            ans += ok
        return ans
