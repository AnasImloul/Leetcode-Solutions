from heapq import heapify, heapreplace

class Solution:
    def largestSumAfterKNegations(self, nums: List[int], k: int) -> int:
        heapify(nums)
        while k and nums[0] < 0:
            heapreplace(nums, -nums[0])
            k -= 1
        if k % 2:
            heapreplace(nums, -nums[0])
        return sum(nums)