# Runtime: 527 ms (Top 22.03%) | Memory: 24.7 MB (Top 71.19%)
class Solution:
    def isGoodArray(self, nums: List[int]) -> bool:
        def gcd(a,b):
            while a:
                a, b = b%a, a
            return b
        return reduce(gcd,nums)==1