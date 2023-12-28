// Runtime: 281 ms (Top 5.06%) | Memory: 22.00 MB (Top 9.58%)

class Solution:
    def kthSmallest(self, matrix, k):
        n, beg, end = len(matrix), matrix[0][0], matrix[-1][-1]
        
        def check(m):
            i, j, cnt = 0, n-1, 0
            for i in range(n):
                while j >= 0 and matrix[i][j] > m: j -= 1
                cnt += (j + 1)
            return cnt
         
        while beg < end:
            mid = (beg + end)//2
            if check(mid) < k:
                beg = mid + 1
            else:
                end = mid
                
        return beg
