// Runtime: 381 ms (Top 86.75%) | Memory: 17.40 MB (Top 70.48%)

class Solution:
    def longestIdealString(self, s: str, k: int) -> int:
        dp = [0] * 26
        for ch in s:
            i = ord(ch) - ord("a")
            dp[i] = 1 + max(dp[max(0, i - k) : min(26, i + k + 1)])
        return max(dp)
