# Runtime: 2589 ms (Top 31.03%) | Memory: 22.20 MB (Top 20.69%)

class Solution:
    def countSubMultisets(self, nums: List[int], l: int, r: int) -> int:
        dp = [1] + [0] * r
        counts = collections.Counter(nums)
        zeros = counts.pop(0, 0) + 1
        for a, c in counts.items():
            stride_sums = dp[:]
            for i in range(a, r + 1):
                stride_sums[i] += stride_sums[i - a]
            for k in range(r, 0, -1):
                dp[k] = stride_sums[k] - stride_sums[k - a * c - a] if k >= a * c + a else stride_sums[k]

        return zeros * sum(dp[l:r+1]) % (10 ** 9 + 7)
