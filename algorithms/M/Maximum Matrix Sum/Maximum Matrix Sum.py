
class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        # count -'s
        count = 0
        for row in matrix:
            for col_num in row:
                if col_num < 0:
                    count += 1
        tot_sum = sum([sum([abs(x) for x in row])
                       for row in matrix])
        if count % 2 == 0:
            return tot_sum
        else:
            min_val = min([min([abs(x) for x in row])
                       for row in matrix])
            return tot_sum - 2 * min_val
