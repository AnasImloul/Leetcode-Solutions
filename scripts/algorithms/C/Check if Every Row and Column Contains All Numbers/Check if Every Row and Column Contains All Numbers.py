class Solution:
    def checkValid(self, matrix: List[List[int]]) -> bool:
        lst = [0]*len(matrix)
        for i in matrix:
            if len(set(i)) != len(matrix):
                return False
            for j in range(len(i)):
                lst[j] += i[j]
        return len(set(lst)) == 1
