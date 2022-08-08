from collections import *
class Solution:
    def maxDistance(self, grid) -> int:
        m,n=len(grid),len(grid[0])
        queue=deque([])
        for i in range(m):
            for j in range(n):
                if grid[i][j]==1:
                    queue.append((i,j))
        c=-1
        while queue:
            # print(queue)
            temp=len(queue)
            for _ in range(temp):
                (i,j)=queue.popleft()
                for (x,y) in ((i-1,j),(i+1,j),(i,j-1),(i,j+1)):
                    if x < 0 or x >= m or y < 0 or y >= n or grid[x][y]==1:
                        continue
                    grid[x][y]=1
                    queue.append((x,y))
            c+=1
        return c if c!=0 else -1
