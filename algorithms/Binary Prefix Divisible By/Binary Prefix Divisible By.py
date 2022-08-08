class Solution:
    def prefixesDivBy5(self, nums: List[int]) -> List[bool]:
        cur = 0
        res = []
        for bit in nums:
            cur = 2*cur + bit
            res.append(cur % 5 == 0)
        return res