// Runtime: 4890 ms (Top 15.42%) | Memory: 42.20 MB (Top 64.95%)

class Solution:
    def minimumObstacles(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        q = [(0, 0, 0)]
        dist = [[float('inf') for _ in range(n)] for _ in range(m)]

        while q:
            size = len(q)
            for _ in range(size):
                obs, x, y = heapq.heappop(q)
                if dist[x][y] < float('inf'): continue
                obs += grid[x][y]
                dist[x][y] = obs
                if x + 1 < m: heapq.heappush(q, (obs, x + 1, y))
                if x > 0: heapq.heappush(q, (obs, x - 1, y))
                if y + 1 < n: heapq.heappush(q, (obs, x, y + 1))
                if y > 0: heapq.heappush(q, (obs, x, y - 1))
        return dist[m - 1][n - 1]
