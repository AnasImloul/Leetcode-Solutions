class Solution:
    def pivotArray(self, nums: List[int], p: int) -> List[int]:
        return [n for n in nums if n < p] + [n for n in nums if n == p] + [n for n in nums if n > p]
