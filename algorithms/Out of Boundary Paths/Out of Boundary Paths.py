class Solution:
    def helper(self, m, n, maxMove, startRow, startColumn, mat,dp) -> int:
        if startRow < 0 or startRow >=m or startColumn < 0 or startColumn >=n:
            return 1
        
        if dp[maxMove][startRow][startColumn]!=-1:
            return dp[maxMove][startRow][startColumn]
        
        if mat[startRow][startColumn]==1:
            return 0
        
        if maxMove <= 0:
            return 0
        
        # mat[startRow][startColumn] = 1
        a = self.helper(m, n, maxMove-1, startRow+1, startColumn,mat,dp)
        b = self.helper(m, n, maxMove-1, startRow-1, startColumn,mat,dp)
        c = self.helper(m, n, maxMove-1, startRow, startColumn+1,mat,dp)
        d = self.helper(m, n, maxMove-1, startRow, startColumn-1,mat,dp)
        dp[maxMove][startRow][startColumn] = a+b+c+d
        return dp[maxMove][startRow][startColumn]
        
        
    def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        mat = [[0 for i in range(n)] for j in range(m)]
        dp = [[[-1 for i in range(n+1)] for j in range(m+1)] for k in range(maxMove+1)]
        return self.helper(m, n, maxMove, startRow, startColumn, mat,dp)%(10**9  + 7) 
    

            
