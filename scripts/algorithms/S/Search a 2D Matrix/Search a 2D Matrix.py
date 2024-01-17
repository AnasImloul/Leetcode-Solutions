// Runtime: 38 ms (Top 96.94%) | Memory: 17.90 MB (Top 11.07%)

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        n = len(matrix[0])
        def get(idx: int) -> int:
            r, c = divmod(idx, n)
            return matrix[r][c]
        return get(bisect_left(range(len(matrix)*n-1), target, key=get)) == target
