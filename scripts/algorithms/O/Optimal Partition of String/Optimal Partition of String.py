// Runtime: 148 ms (Top 20.9%) | Memory: 18.40 MB (Top 11.79%)

class Solution:
    def partitionString(self, s: str) -> int:
        i, ans, flag = 0, 1, 0
        while i < len(s):
            val = ord(s[i]) - ord('a')
            if flag & (1 << val):
                flag = 0
                ans += 1
            flag |= 1 << val
            i += 1
        return ans
