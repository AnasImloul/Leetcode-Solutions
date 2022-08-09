class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        return set(nums) ^ set(range(1,len(nums)+1))
