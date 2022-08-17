class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        
        rows = len(grid)
        cols=len(grid[0])
        grid = [[0]*cols] + grid + [[0]*cols] #add rows of only zeros at top and bottom of grid  
        for i in range(rows+2): 
            grid[i] = [0]+grid[i]+[0] #add cols of only zeros at left and right of grid  
        perimeter=0
        #for each cell that is 1(land) check if its surrounded by 1s or 0s. Add up the number of edges with 0s.
        for row in range(1,rows+1):
            for col in range(1,cols+1):
                if grid[row][col]==1:
                    if grid[row-1][col]==0:
                        perimeter+=1
                    if grid[row+1][col]==0:
                        perimeter+=1
                    if grid[row][col-1]==0:
                        perimeter+=1
                    if grid[row][col+1]==0:
                        perimeter+=1
        return perimeter
