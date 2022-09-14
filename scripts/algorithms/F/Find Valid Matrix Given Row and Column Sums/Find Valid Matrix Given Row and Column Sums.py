# Runtime: 2542 ms (Top 7.54%) | Memory: 19.1 MB (Top 61.04%)
class Solution:
    def restoreMatrix(self, rs: List[int], cs: List[int]) -> List[List[int]]:
        row = len(rs)
        col = len(cs)
        ans = [[0 for i in range(col)] for j in range(row)]
        for i in range(row):
            for j in range(col):
                el = min(rs[i], cs[j])
                ans[i][j] = el
                rs[i] -= el
                cs[j] -= el
        return ans