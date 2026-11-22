# Runtime: 62 ms (Top 46.58%) | Memory: 18.80 MB (Top 100.00%)

class Solution:
    def minimumSum(self, nums: List[int]) -> int:
        n = len(nums)
        l = [0] * n
        r = [0] * n

        l[0] = nums[0]
        r[n - 1] = nums[n - 1]

        for i in range(1, n):
            l[i] = min(l[i - 1], nums[i])

        for i in range(n - 2, -1, -1):
            r[i] = min(r[i + 1], nums[i])

        mn = 2_000_000_000

        for i in range(1, n - 1):
            if l[i] < nums[i] and r[i] < nums[i]:
                mn = min(mn, l[i] + nums[i] + r[i])

        return -1 if mn == 2_000_000_000 else mn
