class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        if len(nums) is 1:
            return 0
        dom = max(nums)
        i = nums.index(dom)
        nums.remove(dom)
        if max(nums) * 2 <= dom:
            return i
        return -1
