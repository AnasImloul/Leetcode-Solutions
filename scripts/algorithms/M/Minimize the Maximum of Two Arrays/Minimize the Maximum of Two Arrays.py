// Runtime: 27 ms (Top 97.3%) | Memory: 16.70 MB (Top 87.18%)

class Solution:
    def minimizeSet(self, divisor1: int, divisor2: int, uniqueCnt1: int, uniqueCnt2: int) -> int:
        uc1 = uniqueCnt1
        uc2 = uniqueCnt2
        d1 = divisor1
        d2 = divisor2
        def gcd(a, b):
            if a == 0:
                return b
            return gcd(b%a, a)
        def valid(n):
            only1 = n // d2 - n // lcm
            only2 = n // d1 - n // lcm
            both = n - n // d1 - n // d2 + n // lcm
            return max(0, uc1 - only1) + max(0, uc2 - only2) <= both
            
        gcd1 = gcd(d1, d2)
        lcm = d1*d2/gcd1
        return bisect_left(range(uniqueCnt1*d1+d2*uniqueCnt2+1), True, lo=1, key=valid)
            
