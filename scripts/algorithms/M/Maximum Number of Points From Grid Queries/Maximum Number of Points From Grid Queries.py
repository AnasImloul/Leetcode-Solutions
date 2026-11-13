# Runtime: 517 ms (Top 68.03%) | Memory: 32.00 MB (Top 100.00%)

class Solution:
    def maxPoints(self, grid: List[List[int]], queries: List[int]) -> List[int]:
        m, n = len(grid), len(grid[0])
        point = []
        prefix = 0 
        prev = -inf 
        pq = [(grid[0][0], 0, 0)]
        grid[0][0] = 0 
        while pq: 
            v, i, j = heappop(pq)
            if prev != v: point.append((prev, prefix))
            prefix += 1
            prev = v
            for ii, jj in (i-1, j), (i, j-1), (i, j+1), (i+1, j): 
                if 0 <= ii < m and 0 <= jj < n and grid[ii][jj]: 
                    vv = max(v, grid[ii][jj])
                    heappush(pq, (vv, ii, jj))
                    grid[ii][jj] = 0
        point.append((prev, prefix))
        ans = []
        for q in queries: 
            i = bisect_left(point, q, key=lambda x: x[0]) - 1
            ans.append(point[i][1])
        return ans
