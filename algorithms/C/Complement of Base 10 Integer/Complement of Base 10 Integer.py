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
        
