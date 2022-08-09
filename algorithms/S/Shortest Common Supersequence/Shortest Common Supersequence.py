class Solution:
    def shortestCommonSupersequence(self, A, B):
        n, m = len(A), len(B)
        dp = [B[:i] for i in range(m + 1)]
        for i in range(n):
            prev = A[:i]
            dp[0] = A[:i + 1]
            for j in range(m):
                if A[i] == B[j]:
                    prev, dp[j + 1] = dp[j + 1], prev + A[i]
                else:
                    prev, dp[j + 1] = dp[j + 1], min(dp[j] + B[j], dp[j + 1] + A[i], key = len)
        return dp[-1]
