class Solution:
    def nthMagicalNumber(self, n: int, a: int, b: int) -> int:
        def gcd(a, b):
            while a > 0:
                a, b = b % a, a
            return b
        def lcm(a, b):
            return a*b//gcd(a,b)
        left, right = min(a,b), n*min(a,b)
        lcm_val = lcm(a,b)
        while left < right:
            m = (left + right)//2
            if m//a + m//b - m//lcm_val >= n:
                right = m
            else:
                left = m + 1
        return left % (10**9 + 7)