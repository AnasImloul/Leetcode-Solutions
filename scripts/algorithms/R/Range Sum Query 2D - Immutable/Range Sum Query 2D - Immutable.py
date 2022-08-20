# Runtime: 3180 ms (Top 18.96%) | Memory: 24.7 MB (Top 69.46%)

class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        m, n = len(matrix), len(matrix[0])
        # Understand why we need to create a new matrix with extra one row/column
        self.sum = [[0 for row in range(n + 1)] for column in range(m + 1)]
        for r in range(1, m + 1):
            for c in range(1, n + 1):
                self.sum[r][c] = self.sum[r - 1][c] + self.sum[r][c - 1] - self.sum[r - 1][c - 1] + matrix[r - 1][c - 1]

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        r1, c1, r2, c2 = row1 + 1, col1 + 1, row2 + 1, col2 + 1
        return self.sum[r2][c2] - self.sum[r1 - 1][c2] - self.sum[r2][c1 - 1] + self.sum[r1 - 1][c1 - 1]

# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)