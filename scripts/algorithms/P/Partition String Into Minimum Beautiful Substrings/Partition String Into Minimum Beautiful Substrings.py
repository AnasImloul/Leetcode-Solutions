// Runtime: 43 ms (Top 82.08%) | Memory: 16.70 MB (Top 61.27%)

powers = tuple(bin(pow(5,i))[2:] for i in range(7))

class Solution:
    def minimumBeautifulSubstrings(self, s: str) -> int:

        def dp(s):
            if s in powers: return 1 
            if not s: return inf
            
            return 1+ min((dp(s[len(p):]) for p in powers
                            if s.startswith(p)), default = inf)

        ans = dp(s)

        return ans if ans != inf else -1
