class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        curmin = nums[0]
        diff = 0
        for num in nums:
            diff = max(diff, num - curmin)
            curmin = min(curmin, num)
        return diff or -1
