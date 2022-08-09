class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        x = Counter(nums)
        return([y for y in x if x[y] == 1])
