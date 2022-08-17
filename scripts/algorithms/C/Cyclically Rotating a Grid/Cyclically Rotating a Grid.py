class Solution:
    def rotateGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        n = len(grid)
        m = len(grid[0])
        
        i, j = 0, 0
        bottom, right = n-1, m-1 
        while i < n//2 and j < m//2:
            temp = []
            for x in range(j, right):
                temp.append(grid[i][x])
            for x in range(i, bottom):
                temp.append(grid[x][right])
            for x in range(right, j, -1):
                temp.append(grid[bottom][x])
            for x in range(bottom, i, -1):
                temp.append(grid[x][j])
                
            
            indx = 0
            for x in range(j, right):
                grid[i][x] = temp[(k + indx)%len(temp)]
                indx += 1
            for x in range(i, bottom):
                grid[x][right] = temp[(k + indx)%len(temp)]
                indx += 1
            for x in range(right, j, -1):
                grid[bottom][x] = temp[(k + indx)%len(temp)]
                indx += 1
            for x in range(bottom, i, -1):
                grid[x][j] = temp[(k + indx)%len(temp)]
                indx += 1
                
            i += 1
            j += 1
            bottom -= 1
            right -= 1
        return grid
