class Solution:
    def rangeAddQueries(self, n: int, queries: List[List[int]]) -> List[List[int]]:
        # initialize the matrix with all zeroes
        mat = [[0] * n for _ in range(n)]
        
        # perform the queries
        for row1, col1, row2, col2 in queries:
            mat[row1][col1] += 1
            if row2+1 < n:
                mat[row2+1][col1] -= 1
            if col2+1 < n:
                mat[row1][col2+1] -= 1
            if row2+1 < n and col2+1 < n:
                mat[row2+1][col2+1] += 1
        
        # update the matrix
        for i in range(n):
            for j in range(1, n):
                mat[i][j] += mat[i][j-1]
        
        for i in range(1, n):
            for j in range(n):
                mat[i][j] += mat[i-1][j]
        
        return mat
