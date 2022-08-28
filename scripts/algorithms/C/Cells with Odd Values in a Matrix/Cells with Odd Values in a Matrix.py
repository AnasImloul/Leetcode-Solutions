// Runtime: 81 ms (Top 40.72%) | Memory: 13.9 MB (Top 91.29%)
class Solution:
    def oddCells(self, row: int, col: int, indices: List[List[int]]) -> int:
        rows, cols = [False] * row, [False] * col

        for index in indices:
            rows[index[0]] = not rows[index[0]]
            cols[index[1]] = not cols[index[1]]

        count = 0
        for i in rows:
            for j in cols:
                count += i ^ j

        return count