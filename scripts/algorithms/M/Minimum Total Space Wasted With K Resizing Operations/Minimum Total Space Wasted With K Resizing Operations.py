class Solution:
    def minSpaceWastedKResizing(self, A: List[int], K: int) -> int:
        def waste(i, j, h):
            sumI = sums[i-1] if i > 0 else 0
            return (j-i+1)*h - sums[j] + sumI
        
        def dp(i, k):
            if i <= k:
                return 0
            if k < 0:
                return MAX
            if (i, k) in memoize:
                return memoize[(i, k)]
            
            _max = A[i]
            r = MAX
            for j in range(i-1, -2, -1):
                r = min(r, dp(j, k-1) + waste(j+1, i,  _max))
                _max = max(_max, A[j])

            memoize[(i, k)] = r
            return r
        
        sums = list(accumulate(A))
        n = len(A)
        MAX = 10**6*200
        memoize = {}

        return dp(n-1, K)