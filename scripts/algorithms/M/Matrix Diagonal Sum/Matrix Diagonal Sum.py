// Runtime: 98 ms (Top 89.16%) | Memory: 17.60 MB (Top 5.05%)

class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        
        n = len(mat)
        
        mid = n // 2
        
        summation = 0
        
        for i in range(n):
            
            # primary diagonal
            summation += mat[i][i]
            
            # secondary diagonal
            summation += mat[n-1-i][i]
            
            
        if n % 2 == 1:
            # remove center element (repeated) on odd side-length case
            summation -= mat[mid][mid]
            
            
        return summation
