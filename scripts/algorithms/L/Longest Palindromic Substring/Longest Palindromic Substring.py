# Runtime: 643 ms (Top 86.54%) | Memory: 14 MB (Top 58.84%)
class Solution:
    def longestPalindrome(self, s: str) -> str:
        res = ""
        for i in range(len(s)):
            left, right = i - 1, i + 1

            while (right < len(s) and s[right] == s[i]):
                right += 1

            while (0 <= left < right < len(s) and s[left] == s[right]):
                left, right = left - 1, right + 1

            res = s[left+1:right] if right - left-1 > len(res) else res
        return res