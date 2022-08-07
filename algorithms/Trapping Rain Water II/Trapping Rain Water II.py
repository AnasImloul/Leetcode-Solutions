import heapq
class Solution:
    def trapRainWater(self, heightMap: List[List[int]]) -> int:
        ROW, COL = len(heightMap), len(heightMap[0])

        pq = []
        heapq.heapify(pq)
        visited = {}
        
        for row in range(ROW):
            for col in range(COL):
                if row == 0 or row == ROW-1 or col == 0 or col == COL-1:
                    heapq.heappush(pq, (heightMap[row][col],row,col))
                    visited[(row,col)] = True
                    
        def getnbr(row,col):
            res = []
            if row-1 >=0:
                res.append((row-1,col))
            if col-1 >=0:
                res.append((row, col-1))
            if row+1 < ROW:
                res.append((row+1,col))
            if col+1 < COL:
                res.append((row, col+1))

            return res
        
        res = 0
        
        while pq:
            h, i, j = heapq.heappop(pq)
            
            for dx, dy in getnbr(i,j):
                if (dx,dy) not in visited:  
                    
                    res += max(0, h-heightMap[dx][dy])
                    
                    heapq.heappush(pq, (max(h, heightMap[dx][dy]),dx,dy))
                    visited[(dx,dy)] = True

        return res
