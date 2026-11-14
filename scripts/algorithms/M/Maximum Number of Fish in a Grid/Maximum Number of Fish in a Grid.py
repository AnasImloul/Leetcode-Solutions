# Runtime: 27 ms (Top 87.81%) | Memory: 19.20 MB (Top 88.26%)

class Solution:
    def findMaxFish(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        ans = 0
        dr = [0, 1, 0, -1]
        dc = [1, 0, -1, 0]
        for i in range(n):
            for j in range(m):
                if grid[i][j] > 0:
                    q = deque()
                    q.append((i, j))
                    f = grid[i][j]
                    grid[i][j] = 0
                    while q:
                        curr = q.popleft()
                        for k in range(4):
                            nr = curr[0] + dr[k]
                            nc = curr[1] + dc[k]
                            if nr >= 0 and nr < n and nc >= 0 and nc < m and grid[nr][nc] > 0:
                                f += grid[nr][nc]
                                grid[nr][nc] = 0
                                q.append((nr, nc))
                    ans = max(ans, f)
        return ans
