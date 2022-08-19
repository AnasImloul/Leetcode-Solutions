# Runtime: 353 ms (Top 84.15%) | Memory: 28.7 MB (Top 5.01%)

seen=set()
def dfs(i,j,m,n,grid):
    global seen
    if (i<0 or i>=m or j<0 or j>=n):return
    if (i,j) in seen:return
    seen.add((i,j))
    if grid[i][j]=="1":
        dfs(i,j+1,m,n,grid)
        dfs(i,j-1,m,n,grid)
        dfs(i+1,j,m,n,grid)
        dfs(i-1,j,m,n,grid)

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        global seen
        m=len(grid) #no of rows
        n=len(grid[0]) #no of columns
        count=0
        for i in range(m):
            for j in range(n):
                if (i,j) not in seen and grid[i][j]=="1":
                    dfs(i,j,m,n,grid)
                    count+=1
        seen.clear()
        return count