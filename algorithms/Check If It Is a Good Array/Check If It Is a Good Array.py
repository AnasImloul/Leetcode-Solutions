class Solution:
    def isGoodArray(self, nums: List[int]) -> bool:
        def gcd(a,b):
            while a:
                a, b = b%a, a
            return b
        return reduce(gcd,nums)==1