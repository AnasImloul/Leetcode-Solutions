from typing import List
from collections import Counter


class Solution:
    def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
        counter = Counter()
        max_val = 2 ** len(matrix[0]) - 1
        for row in matrix:
            v = self.calculate_binary(row)
            counter[v] += 1
            counter[max_val - v] += 1
            # print(f'counter: {counter}')

        return counter.most_common(1)[0][1]

    def calculate_binary(self, row: List[int]) -> int:
        val = 0
        for r in row:
            val = val * 2 + r
        return val
