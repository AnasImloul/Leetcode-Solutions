# Runtime: 0 ms (Top 100.00%) | Memory: 32.30 MB (Top 58.12%)

class Solution:
    def minLengthAfterRemovals(self, nums: List[int]) -> int:
        n = len(nums)
        i = nums[n // 2]
        cnt = bisect_right(nums, i) - bisect_left(nums, i)
        return max(n % 2, 2 * cnt - n)
