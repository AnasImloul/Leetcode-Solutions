class Solution:
    def containsCycle(self, grid: List[List[str]]) -> bool:
        
        def getNeighbours(row,col,char):
            neighbours = []
            if row > 0 and grid[row-1][col] == char and not visited[row-1][col]:
                neighbours.append([row-1,col])
            if col > 0 and grid[row][col-1] == char and not visited[row][col-1]:
                neighbours.append([row,col-1])
            if row < len(grid)-1 and grid[row+1][col] == char and not visited[row+1][col]:
                neighbours.append([row+1,col])
            if col < len(grid[0])-1 and grid[row][col+1] == char and not visited[row][col+1]:
                neighbours.append([row,col+1])
            return neighbours
        
        def dfs(row,col,char,cyclePresent):
            if visited[row][col] or cyclePresent:
                cyclePresent = True
                return cyclePresent
            visited[row][col] = True
            neighbours = getNeighbours(row,col,char)
            for r,c in neighbours:
                cyclePresent = dfs(r,c,char,cyclePresent)
            return cyclePresent
        
        visited = [[False for _ in range(len(grid[0]))] for _ in range(len(grid))]
        cyclePresent = False
        for row in range(len(grid)):
            for col in range(len(grid[0])):
                if cyclePresent:
                    return True
                if visited[row][col]:
                    continue
                cyclePresent = dfs(row,col,grid[row][col],cyclePresent)
        
        return cyclePresent
