# Runtime: 3044 ms (Top 67.44%) | Memory: 67.7 MB (Top 72.09%)

class Solution:
    def longestPalindrome(self, word1: str, word2: str) -> int:
        s1 = word1 + word2
        n = len(s1)
        dp = [[0] * n for i in range(n)]
        ans = 0
        for i in range(n-1,-1,-1):
        # mark every character as a 1 length palindrome
            dp[i][i] = 1
            for j in range(i+1,n):
            # new palindrome is found
                if s1[i] == s1[j]:
                    dp[i][j] = dp[i+1][j-1] + 2
                    # if the palindrome includes both string consider it as a valid
                    if i < len(word1) and j >= len(word1):
                        ans = max(ans,dp[i][j])
                else:
                    dp[i][j] = max(dp[i][j-1],dp[i+1][j])

        return ans