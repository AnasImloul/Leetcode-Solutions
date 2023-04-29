class Solution:
    def maxPower(self, s):
        cnt = 0
        m = 0
        for i in range(1, len(s)):
            if (s[i-1] == s[i]): 
                cnt += 1
                m = max(cnt, m)
            else: cnt = 0
        return m + 1