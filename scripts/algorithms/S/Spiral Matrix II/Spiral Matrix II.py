// Runtime: 34 ms (Top 84.25%) | Memory: 16.50 MB (Top 59.83%)

class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        if not n:
            return []
        matrix = [[0 for _ in range(n)] for _ in range(n)]
        left, right, top, bottom, num = 0, n-1, 0, n-1, 1
        while left <= right and top <= bottom:
            for i in range(left, right+1):
                matrix[top][i] = num 
                num += 1
            top += 1
            for i in range(top, bottom+1):
                matrix[i][right] = num
                num += 1
            right -= 1
            if top <= bottom:
                for i in range(right, left-1, -1):
                    matrix[bottom][i] = num
                    num += 1
                bottom -= 1
            if left <= right:
                for i in range(bottom, top-1, -1):
                    matrix[i][left] = num
                    num += 1
                left += 1
        return matrix

