class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        
        visited = [ [0 for _ in range(cols)] for _ in range(rows) ]
        distances = [ [math.inf for _ in range(cols)] for _ in range(rows) ]
        distances[0][0] = grid[0][0]
        queue = [(0,0,0)] # distance, i,j of first point to visit in the Djikstra traversal
                
        while visited[-1][-1]==0: # no need to traverse entire graph, can end when bottom-right cell distance to origin is known
            
            distance, i, j = heapq.heappop(queue) # use a minheap to track what cell to visit next
            visited[i][j] = 1
            
            for di, dj in [[0,-1],[0,1],[-1,0],[1,0]]:
                adj_i = i + di
                adj_j = j + dj
                
                if 0<=adj_i<rows and 0<=adj_j<cols and visited[adj_i][adj_j]==0:
                
                    adj_dist = distances[i][j] + max(grid[adj_i][adj_j]-distances[i][j],0) # ensures minpath is never reduced

                    if adj_dist < distances[adj_i][adj_j]:
                        distances[adj_i][adj_j] = adj_dist
                        heapq.heappush(queue,(adj_dist,adj_i,adj_j))
        
        return distances[-1][-1]        
