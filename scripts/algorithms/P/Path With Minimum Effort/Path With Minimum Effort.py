# Runtime: 1804 ms (Top 36.30%) | Memory: 15.4 MB (Top 76.73%)
class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        di = (0, 1, 0, -1)
        dj = (1, 0, -1, 0)
        m, n = len(heights), len(heights[0])
        visited = [[False] * n for _ in range(m)]
        h = [(0, 0, 0)]
        while h:
            effort, i, j = heappop(h)
            if visited[i][j]:
                continue
            visited[i][j] = True
            if i + 1 == m and j + 1 == n:
                return effort ## have reached the (m-1, n-1) cell
            for k in range(4):
                ii, jj = i + di[k], j + dj[k]
                if 0 <= ii < m and 0 <= jj < n and not visited[ii][jj]:
                    neffort = max(effort, abs(heights[i][j] - heights[ii][jj]))
                    heappush(h, (neffort, ii, jj))
        return ## cell (m-1, n-1) not reachable, should never happen