// Runtime: 137 ms (Top 88.55%) | Memory: 14.9 MB (Top 82.23%)
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