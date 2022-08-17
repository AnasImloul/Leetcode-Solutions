class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        min_, max_ = 0, 0
        min_temp = []
        max_temp = []
        m = len(matrix)
        n = len(matrix[0])
        for i in matrix:
            min_temp.append(min(i))
        print(min_temp)
        if n >= m:
            for i in range(n):
                max_check = []
                for j in range(m):
                    max_check.append(matrix[j][i])
                max_temp.append(max(max_check))
            return set(min_temp).intersection(set(max_temp))
        elif n == 1:
            for i in range(m):
                max_check = []
                for j in range(n):
                    max_check.append(matrix[i][j])
                max_temp.append(max(max_check))
            return [max(max_temp)]
        else:
            for i in range(n):
                max_check = []
                for j in range(m):
                    max_check.append(matrix[j][i])
                max_temp.append(max(max_check))
            return set(min_temp).intersection(set(max_temp))
