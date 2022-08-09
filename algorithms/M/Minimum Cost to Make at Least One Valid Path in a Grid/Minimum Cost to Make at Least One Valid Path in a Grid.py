class Solution:
    def minCost(self, grid: List[List[int]]) -> int:
        changes = [[float("inf") for _ in range(len(grid[0]))] for _ in range(len(grid))]
        heap = [(0,0,0)]
        dirn = [(0,1),(0,-1),(1,0),(-1,0)]
        while heap:
            dist,r,c = heapq.heappop(heap)
            if r >= len(grid) or r < 0 or c >= len(grid[0]) or c < 0 or changes[r][c] <= dist:
                continue
            if r == len(grid) - 1 and c == len(grid[0]) - 1:
                return dist
            changes[r][c] = dist
            for i in range(1,5):
                if i == grid[r][c]:
                    heapq.heappush(heap,(dist,r+dirn[i-1][0],c+dirn[i-1][1]))
                else:
                    heapq.heappush(heap,(dist+1,r+dirn[i-1][0],c+dirn[i-1][1]))
        return dist
                    
