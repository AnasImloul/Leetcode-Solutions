from collections import deque

class Solution:
    def cutOffTree(self, forest: List[List[int]]) -> int:
        a = []
        n = len(forest)
        m = len(forest[0])
        for i in range(n):
            for j in range(m):
                if forest[i][j] > 1:
                    a.append(forest[i][j])
        a.sort()
        
        s = 0
        ux = 0
        uy = 0
        for h in a:
            dist = [[None] * m for i in range(n)]
            q = deque()
            q.append((ux, uy))
            dist[ux][uy] = 0
            while q:
                ux, uy = q.popleft()
                if forest[ux][uy] == h:
                    break
                d = [(-1, 0), (0, 1), (1, 0), (0, -1)]
                for dx, dy in d:
                    vx = ux + dx
                    vy = uy + dy
                    if vx < 0 or vx >= n or vy < 0 or vy >= m:
                        continue
                    if forest[vx][vy] == 0:
                        continue
                    if dist[vx][vy] is None:
                        q.append((vx, vy))
                        dist[vx][vy] = dist[ux][uy] + 1
            if forest[ux][uy] == h:
                s += dist[ux][uy]
            else:
                return -1
        return s
