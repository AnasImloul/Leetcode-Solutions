class Solution:
    def minimizedMaximum(self, n: int, quantities: List[int]) -> int:
        def cond(m, n):
            return sum([(q // m) + (q % m > 0) for q in quantities]) <= n
        
        l, r = 1, max(quantities)
        while l < r:
            m = (l + r) // 2
            if cond(m, n):
                r = m
            else:
                l = m + 1
        return l
