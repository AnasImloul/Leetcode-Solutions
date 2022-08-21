# Runtime: 205 ms (Top 93.96%) | Memory: 14.3 MB (Top 84.02%)

class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:

        m,n=len(grid),len(grid[0])
        for i in range(m):
            grid[i].insert(0,1)
            grid[i].append(-1)
        res=[]

        for k in range(1,n+1):
            i , j = 0 , k
            struck = False
            while i<m:
                if grid[i][j]==1:
                    if grid[i][j+1]==1:
                        j+=1
                    else:
                        struck=True
                        break
                else:
                    if grid[i][j-1]==-1:
                        j-=1
                    else:
                        struck=True
                        break
                i+=1
            if struck:
                res.append(-1)
            else:
                res.append(j-1)

        return res