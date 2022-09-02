# Runtime: 77 ms (Top 19.02%) | Memory: 14.8 MB (Top 20.86%)
class Solution:
    def soupServings(self, n: int) -> float:
        if n >= 4276: return 1.0

        @lru_cache(None)
        def f(a: int, b: int)->float:
            if a <= 0 and b <= 0: return 0.5
            if a <= 0: return 1
            if b <= 0: return 0
            return (f(a-100,b) + f(a-75,b-25) + f(a-50,b-50) + f(a-25,b-75))*.25

        return f(n,n)