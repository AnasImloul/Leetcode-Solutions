# Runtime: 308 ms (Top 20.31%) | Memory: 15.2 MB (Top 51.05%)
class Solution:
    def matrixBlockSum(self, matrix: List[List[int]], k: int) -> List[List[int]]:
        ROWS, COLS = len(matrix), len(matrix[0])

        prefix_sums = [[0] * (COLS + 1) for _ in range(ROWS + 1)]

        for r in range(1, ROWS + 1):
            for c in range(1, COLS + 1):
                prefix_sums[r][c] = prefix_sums[r - 1][c] + prefix_sums[r][c - 1] + \
                    matrix[r - 1][c - 1] - prefix_sums[r - 1][c - 1]

        res = [[0] * COLS for _ in range(ROWS)]
        for r in range(ROWS):
            for c in range(COLS):
                res[r][c] = prefix_sums[min(r + k + 1, ROWS)][min(c + k + 1, COLS)] - \
                    prefix_sums[max(r - k, 0)][min(c + k + 1, COLS)] - \
                    prefix_sums[min(r + k + 1, ROWS)][max(c - k, 0)] + \
                    prefix_sums[max(r - k, 0)][max(c - k, 0)]

        return res