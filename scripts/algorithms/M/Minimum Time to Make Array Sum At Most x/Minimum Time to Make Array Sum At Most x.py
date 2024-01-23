// Runtime: 1096 ms (Top 74.31%) | Memory: 16.70 MB (Top 84.4%)

class Solution:
    def minimumTime(self, nums1: List[int], nums2: List[int], x: int) -> int:
        n = len(nums1)
        ind = list(range(n))
        s, d = 0, 0
        for i in range(n):
            s += nums1[i]
            d += nums2[i]
        if s <= x:
            return 0

        # Custom comparator for sorting ind based on nums2 values
        ind.sort(key=lambda i: nums2[i])

        dp = [0] * (n + 1)
        r = n + 1
        for i in range(1, n + 1):
            for j in range(min(i, r - 1), 0, -1):
                dp[j] = max(dp[j], dp[j - 1] + nums2[ind[i - 1]] * j + nums1[ind[i - 1]])
                if s + j * d - dp[j] <= x:
                    r = j
        return r if r <= n else -1
