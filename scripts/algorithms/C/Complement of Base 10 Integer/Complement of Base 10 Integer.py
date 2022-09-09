# Runtime: 50 ms (Top 42.69%) | Memory: 13.9 MB (Top 55.15%)
class Solution(object):
    def bitwiseComplement(self, n):
        m = n
        mask = 0

        if n==0:
            return 1
        while m:
            mask = (mask << 1) | 1
            m = m>>1

        ans = mask & (~n)
        return ans
