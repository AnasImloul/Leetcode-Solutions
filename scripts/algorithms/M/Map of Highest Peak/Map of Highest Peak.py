class Solution:
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        arr = collections.deque()
        m, n = len(isWater), len(isWater[0])
        for i in range(m):
            for j in range(n):
                if isWater[i][j] == 1:
                    arr.append((0, i, j))
                    
        ans = [[-1] * n for _ in range(m)]
        while arr:
            val, x, y = arr.popleft() 
            if ans[x][y] != -1: continue
            ans[x][y] = val
            for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                xx, yy = x+dx, y+dy
                if 0 <= xx < m and 0 <= yy < n and ans[xx][yy] == -1:
                    arr.append((val+1, xx, yy))
        return ans
