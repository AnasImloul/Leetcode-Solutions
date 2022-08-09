class Solution:

    def minPathSum(self, grid: List[List[int]]) -> int:
        prev=[0]*len(grid[0])
        for i in range(len(grid)):
            temp=[0]*len(grid[0])
            for j in range(len(grid[0])):
                if i==0 and j==0:
                    temp[j]=grid[i][j]
                    continue
                if i>0:
                    lft=grid[i][j]+prev[j]
                else:
                    lft=grid[i][j]+1000
                if j>0:
                    up=grid[i][j]+temp[j-1]
                else:
                    up=grid[i][j]+1000
                temp[j]=min(up,lft)
            prev=temp
        return prev[-1]
    
        
