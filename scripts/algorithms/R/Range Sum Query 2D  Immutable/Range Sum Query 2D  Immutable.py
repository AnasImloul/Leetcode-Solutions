// Runtime: 1010 ms (Top 99.39%) | Memory: 28.30 MB (Top 14.0%)

class NumMatrix:
    def __init__(self, matrix: List[List[int]]):
        m, n = len(matrix), len(matrix[0])
        self.sum = [[0] * (n + 1) for _ in range(m + 1)]  # sum[i][j] is sum of all elements inside the rectangle [0,0,i,j]
        for r in range(1, m + 1):
            for c in range(1, n + 1):
                self.sum[r][c] = self.sum[r - 1][c] + self.sum[r][c - 1] - self.sum[r - 1][c - 1] + matrix[r - 1][c - 1]

    def sumRegion(self, r1: int, c1: int, r2: int, c2: int) -> int:
        r1, c1, r2, c2 = r1 + 1, c1 + 1, r2 + 1, c2 + 1  # Since our `sum` starts by 1 so we need to increase r1, c1, r2, c2 by 1
        return self.sum[r2][c2] - self.sum[r2][c1 - 1] - self.sum[r1 - 1][c2] + self.sum[r1 - 1][c1 - 1]
