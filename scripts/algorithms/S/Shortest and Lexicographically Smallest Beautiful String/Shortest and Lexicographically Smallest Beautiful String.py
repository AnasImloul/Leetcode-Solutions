# Runtime: 1 ms (Top 72.65%) | Memory: 19.20 MB (Top 53.17%)

class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:

        ones = [i for i, digit in enumerate(s) if digit == '1']     # <-- 1.

        if len(ones) < k: return ''

        cands = list(zip(ones,ones[k-1:]))                          
        minLen = min(r-l for l, r in cands)                         # <-- 2.

        cands = filter(lambda x: x[1]-x[0] == minLen, cands)        # <-- 3.

        return min([s[l:r+1] for l,r in cands])                     # <-- 4.
