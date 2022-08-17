class Solution:
    def xorGame(self, nums: List[int]) -> bool:
        return not reduce(lambda a,b: a^b, nums) or not len(nums)%2