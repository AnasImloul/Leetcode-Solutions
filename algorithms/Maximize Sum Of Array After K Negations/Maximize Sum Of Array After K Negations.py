class Solution:
    def largestSumAfterKNegations(self, nums: List[int], k: int) -> int:
        for i in range(k):
            x = min(nums)
            y = nums.index(x)
            nums[y] = -1*x
        return sum(nums)
