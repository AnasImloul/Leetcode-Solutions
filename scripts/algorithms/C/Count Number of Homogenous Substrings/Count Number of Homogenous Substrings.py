# Runtime: 127 ms (Top 59.9%) | Memory: 17.38 MB (Top 67.5%)

class Solution:
    def countHomogenous(self, s: str) -> int:
        res, count, n = 0, 1, len(s)
        for i in range(1,n):
            if s[i]==s[i-1]:
                count+=1
            else:
                if count>1:
                    res+=(count*(count-1)//2)
                count=1    
        if count>1:
            res+=(count*(count-1)//2)
        return (res+n)%(10**9+7)