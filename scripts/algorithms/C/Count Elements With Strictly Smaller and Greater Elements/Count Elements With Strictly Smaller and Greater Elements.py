class Solution:
    def countElements(self, nums: List[int]) -> int:
        M = max(nums)
        m = min(nums)
        return sum(1 for i in nums if m<i<M)
