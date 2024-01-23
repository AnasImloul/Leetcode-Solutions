// Runtime: 887 ms (Top 94.77%) | Memory: 48.10 MB (Top 59.48%)

class Solution:
    def findPeakGrid(self, mat: List[List[int]]) -> List[int]:
        m, n = len(mat), len(mat[0])
        l, r = 0, n
        while l <= r:
            mid = (l + r) // 2
            cur_max, left = 0, False
            for i in range(m):
                if i > 0 and mat[i-1][mid] >= mat[i][mid]:
                    continue
                if i+1 < m and mat[i+1][mid] >= mat[i][mid]:   
                    continue
                if mid+1 < n and mat[i][mid+1] >= mat[i][mid]:   
                    cur_max, left = mat[i][mid], not mat[i][mid] > cur_max
                    continue
                if mid > 0 and mat[i][mid-1] >= mat[i][mid]:   
                    cur_max, left = mat[i][mid], mat[i][mid] > cur_max
                    continue
                return [i, mid]
            if left:
                r = mid-1
            else:
                l = mid+1
        return []
