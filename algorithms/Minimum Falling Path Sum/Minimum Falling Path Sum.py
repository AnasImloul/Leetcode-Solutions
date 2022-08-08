class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        for row in range(1, len(matrix)):
            for col in range(0, len(matrix[row])):
                if col == 0:
                    matrix[row][col] += min(matrix[row-1][col+1], matrix[row-1][col])
                elif col == len(matrix[row]) - 1:
                    matrix[row][col] += min(matrix[row-1][col-1], matrix[row-1][col])
                else:
                    matrix[row][col] += min(matrix[row-1][col-1], matrix[row-1][col], matrix[row-1][col+1])
                
        return min(matrix[-1])
