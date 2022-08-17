from itertools import accumulate

class Solution:
    def rangeSum(self, nums, n, left, right):
        acc = []

        for i in range(n):
            acc.extend(accumulate(nums[i:]))

        acc.sort()

        return sum(acc[left - 1:right]) % (10**9 + 7)
