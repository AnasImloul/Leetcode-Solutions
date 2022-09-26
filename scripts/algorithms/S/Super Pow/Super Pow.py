# Runtime: 260 ms (Top 32.64%) | Memory: 13.9 MB (Top 58.72%)
class Solution:
    def superPow(self, a: int, b: List[int]) -> int:
        mod = 1337
        ans = 1

        for power in b:
            ans = ((pow(ans,10)%mod)*(pow(a,power)%mod))%mod

        return ans