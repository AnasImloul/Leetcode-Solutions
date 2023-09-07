# Runtime: 1888 ms (Top 33.3%) | Memory: 33.75 MB (Top 100.0%)

class Solution(object):
    def rangeAddQueries(self, n, queries):
        mat = [[0] * (n + 1) for _ in range(n + 1)]
        
        for startRow, startCol, endRow, endCol in queries:
            for r in range(startRow, endRow + 1):
                mat[r][startCol] += 1
                mat[r][endCol + 1] -= 1

        
        
        for i in range(n):
            for j in range(1, n):
                mat[i][j] += mat[i][j - 1]

        
        ans = [[0] * n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                ans[i][j] = mat[i][j]

        return ans

           

        