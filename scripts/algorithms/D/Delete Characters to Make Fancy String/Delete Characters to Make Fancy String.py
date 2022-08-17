class Solution:
    def makeFancyString(self, s: str) -> str:
        if len(s) < 3:
            return s
        ans = ''
        ans += s[0]
        ans += s[1]
        for i in range(2,len(s)):
            if s[i] != ans[-1] or s[i] != ans[-2]:
                ans += s[i]
        return ans
