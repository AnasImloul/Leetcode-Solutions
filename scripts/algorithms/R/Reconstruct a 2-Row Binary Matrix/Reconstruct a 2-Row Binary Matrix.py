# Runtime: 2054 ms (Top 5.33%) | Memory: 24.4 MB (Top 72.78%)
class Solution:
    def reconstructMatrix(self, upper: int, lower: int, colsum: List[int]) -> List[List[int]]:
        n = len(colsum)
        matrix = [[0 for i in range(n)] for j in range(2)]
        for col,summ in enumerate(colsum):
            if summ == 0:
                continue
            if summ == 2:
                matrix[0][col] = matrix[1][col] = 1
                upper -= 1
                lower -= 1
            else:
                if upper > lower:
                    matrix[0][col] = 1
                    upper -= 1
                else:
                    matrix[1][col] = 1
                    lower -= 1
            if upper < 0 or lower < 0: break

        return matrix if upper == lower == 0 else []