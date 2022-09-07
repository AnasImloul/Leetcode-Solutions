# Runtime: 342 ms (Top 15.25%) | Memory: 15.2 MB (Top 92.14%)
class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        right = sum(nums)
        left = 0

        for i in range(len(nums)):
            right -= nums[i]
            left += nums[i - 1] if i > 0 else 0

            if right == left: return i

        return -1