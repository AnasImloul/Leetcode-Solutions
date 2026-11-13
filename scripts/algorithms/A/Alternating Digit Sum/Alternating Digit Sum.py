# Runtime: 1 ms (Top 6.66%) | Memory: 19.00 MB (Top 98.53%)

class Solution:
    def alternateDigitSum(self, n: int) -> int:
        s=str(n)
        ans=0
        for i in range(0,len(s),2):
            ans+=int(s[i])
        for i in range(1,len(s),2):
            ans-=int(s[i])
        return ans
