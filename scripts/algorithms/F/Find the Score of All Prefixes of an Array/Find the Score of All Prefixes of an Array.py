class Solution:
    def findPrefixScore(self, nums: List[int]) -> List[int]:
        return accumulate(map(add, nums, accumulate(nums, max)))