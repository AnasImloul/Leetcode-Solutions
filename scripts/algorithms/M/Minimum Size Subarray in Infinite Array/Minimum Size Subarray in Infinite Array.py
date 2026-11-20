# Runtime: 77 ms (Top 68.47%) | Memory: 29.10 MB (Top 77.48%)

class Solution:
    def minSizeSubarray(self, nums: List[int], target: int) -> int:
        n, total, windowSum, start = len(nums), sum(nums), 0, 0
        partial, complete = n, n * (target // total)
        target %= total
        for end in range(2 * n):
            windowSum += nums[end % n]
            while windowSum > target:
                windowSum -= nums[start % n]
                start += 1
            if windowSum == target:
                partial = min(partial, end - start + 1)
        return partial + complete if partial != n else -1
