# Runtime: 127 ms (Top 17.65%) | Memory: 13.9 MB (Top 92.19%)
class Solution:
    def largestSumAfterKNegations(self, nums: List[int], k: int) -> int:
        for i in range(k):
            x = min(nums)
            y = nums.index(x)
            nums[y] = -1*x
        return sum(nums)