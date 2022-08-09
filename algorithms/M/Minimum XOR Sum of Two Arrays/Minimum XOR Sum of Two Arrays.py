class Solution:
    def minimumXORSum(self, a: List[int], b: List[int]) -> int:
        @cache
        def dp(mask: int) -> int:
            i = bin(mask).count("1")
            if i >= len(a):
                return 0
            return min((a[i] ^ b[j]) + dp(mask + (1 << j)) 
                       for j in range(len(b)) if mask & (1 << j) == 0)
        return dp(0)
