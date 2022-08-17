class Solution:
    def numSmaller(self, x, m, n):
        res = 0
        for i in range(1, m + 1):
            res += min(x // i, n)
        return res
    
    def findKthNumber(self, m: int, n: int, k: int) -> int:
        beg = 1
        end = m * n
        while beg < end:
            mid = (beg + end) // 2
            curr = self.numSmaller(mid, m, n)
            if curr < k:
                beg = mid + 1
            else:
                end = mid
        return beg
