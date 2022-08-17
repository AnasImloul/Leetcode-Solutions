class Solution:
    def maxPower(self, s: str) -> int:
        m=1
        ans=1
        for i in range(1,len(s)):
            if s[i]!=s[i-1]:
                m=1
            else:
                m+=1
                ans=max(ans,m)
        return ans
