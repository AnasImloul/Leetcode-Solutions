class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        # 3-D DP
        # dp Approach
        # Bottom-Up
        r=len(grid)
        c=len(grid[0])        
        dp=[[[0 for _ in range(c)] for _ in range(c)] for _ in range(r)]
        for i in range(r):
            for j1 in range(c):
                for j2 in range(c):
                    if i==r-1 and j1==j2:
                        dp[i][j1][j2]=grid[i][j1]
                    elif(i==r-1):
                        dp[i][j1][j2]=grid[i][j1]+grid[i][j2]
        for i in range(r-2,-1,-1):
            for j1 in range(c):
                for j2 in range(c):
                    maxi=-float('inf')
                    for dj1 in range(-1,2):
                        for dj2 in range(-1,2):
                            if j1==j2:
                                value=grid[i][j1]
                            else:
                                value=grid[i][j1]+grid[i][j2]
                            if j1+dj1>=0 and j1+dj1<c and j2+dj2>=0 and j2+dj2<c:
                                value+=dp[i+1][j1+dj1][j2+dj2]
                            else:
                                value=-float('inf')
                            maxi=max(maxi,value)
                    dp[i][j1][j2]=maxi
        return dp[0][0][c-1]

#         Memoization

        r=len(grid)
        c=len(grid[0])
        def solve(i,j1,j2):
            dp=[[[-1 for _ in range(c)] for _ in range(c)] for _ in range(r)]
            if j1<0 or j1>=c or j2<0 or j2>=c:
                return -float('inf')
            if i==r-1:
                if j1==j2:
                    return grid[i][j1]
                else:
                    return grid[i][j1]+grid[i][j2]
            maxi=-float('inf')
            if dp[i][j1][j2]!=-1:
                return dp[i][j1][j2]
            for dj1 in range(-1,2):
                for dj2 in range(-1,2):
                    if j1==j2:
                        maxi=max(maxi,grid[i][j1]+solve(i+1,j1+dj1,j2+dj2))
                    else:
                        maxi=max(maxi,grid[i][j1]+grid[i][j2]+solve(i+1,j1+dj1,j2+dj2))
            dp[i][j1][j2]=maxi
            return dp[i][j1][j2]
        return solve(0,0,c-1)

