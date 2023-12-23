// Runtime: 593 ms (Top 63.06%) | Memory: 17.30 MB (Top 29.73%)

class Solution:
    def findKthNumber(self, m, n, k):
        def count(x):
            return sum(min(x//i, n) for i in range(1,m+1))
			
        L, R, mid, ans = 0, m*n, 0, 0
        while L <= R:
            mid = (L + R) >> 1
            if count(mid) < k:
                L = mid + 1
            else:
                R, ans = mid - 1, mid
        return ans
