class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        col, row = len(matrix[0]), len(matrix)
        l, t, r, b = 0, 0, col - 1, row - 1
        res = []
        while l <= r and t <= b:
            for i in range(l, r):
                res.append(matrix[t][i])
            for i in range(t, b):
                res.append(matrix[i][r])
            
			# Append the orphan left by the open interval
            if t == b:
                res.append(matrix[t][r])
            else:
                # From right to left at the bottom
                for i in range(r, l, -1):
                    res.append(matrix[b][i])
            
			# Avoid duplicated appending if it is a square
            if l == r and t != b:
                res.append(matrix[b][r])
            else:
                # From bottom to top at the left
                for i in range(b, t, -1):
                    res.append(matrix[i][l])
            l += 1
            t += 1
            r -= 1
            b -= 1

        return res
