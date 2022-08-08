class Solution:
    def sumSubseqWidths(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        M = 10**9+7
        res = 0
        le = 1
        re = pow(2, n-1, M)
        #by Fermat's Little Thm
        #inverse of 2 modulo M
        inv = pow(2, M-2, M)
        for num in nums:
            res = (res + num * (le - re))%M
            le = (le * 2) % M
            re = (re * inv) % M
        return res