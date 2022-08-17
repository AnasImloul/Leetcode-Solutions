class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        return [i for t in zip([p for p in nums if p > 0], [n for n in nums if n < 0]) for i in t]
