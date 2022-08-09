class Solution:
    def largestSumOfAverages(self, A, k):
        n = len(A)
        dp = [0] * n
        sum = 0
        for i in range(n-1,-1,-1):
            sum += A[i]
            dp[i] = sum / (n-i)
        for l in range(1,k):
            for i in range(n-l):
                sum = 0
                for j in range(i,n-l):
                    sum += A[j]
                    dp[i] = max(dp[i],dp[j+1] + sum / (j-i+1))
        return dp[0]
