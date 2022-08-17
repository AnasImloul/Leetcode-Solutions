class Solution:

    digits = {1, 2, 3, 4, 5, 6, 7, 8, 9}

    @classmethod
    def magic_3_3(cls, square: List[List[int]]) -> bool:
        if set(sum(square, [])) != Solution.digits:
            return False
        sum_row0 = sum(square[0])
        for r in range(1, 3):
            if sum(square[r]) != sum_row0:
                return False
        if any(sum(col) != sum_row0 for col in zip(*square)):
            return False
        sum_main_diagonal = sum_second_diagonal = 0
        for i in range(3):
            sum_main_diagonal += square[i][i]
            sum_second_diagonal += square[i][2 - i]
        return sum_main_diagonal == sum_second_diagonal == sum_row0

    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        count = 0
        rows, cols = len(grid), len(grid[0])
        for r in range(rows - 2):
            for c in range(cols - 2):
                if Solution.magic_3_3([grid[row_idx][c: c + 3]
                                       for row_idx in range(r, r + 3)]):
                    count += 1
        return count
