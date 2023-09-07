# Runtime: 207 ms (Top 30.9%) | Memory: 16.40 MB (Top 96.4%)

class Solution:
    def leftRightDifference(self, nums: List[int]) -> List[int]:
        return [abs(sum(nums[:i + 1]) - sum(nums[i:])) for i in range(len(nums))]