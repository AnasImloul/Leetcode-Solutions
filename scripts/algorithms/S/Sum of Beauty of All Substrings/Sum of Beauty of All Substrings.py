class Solution:
    def beautySum(self, s: str) -> int:
        c, n, ans = Counter(s), len(s), 0
        for i in range(n-2):
            x=c.copy()
            for j in range(n-1,i+1,-1):
                ans+=max(x.values())-min(x.values())
                if x[s[j]]==1:
                    del x[s[j]]
                else:
                    x[s[j]]-=1
            if c[s[i]]==1:
                del c[s[i]]
            else:
                c[s[i]]-=1
        return ans
