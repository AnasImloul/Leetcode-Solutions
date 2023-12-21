// Runtime: 38 ms (Top 52.6%) | Memory: 17.10 MB (Top 12.47%)

class Solution:
    def bitwiseComplement(self, n: int) -> int:
        cnt=0
        ans=0
        if n==0:
            return 1
        while n>0:
            if n&1:
                cnt+=1
            else:
                ans =ans +(2**cnt)
                cnt+=1
            n=n>>1
        return ans
