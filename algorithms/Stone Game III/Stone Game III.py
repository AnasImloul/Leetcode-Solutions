class Solution(object):
    def stoneGameIII(self, stoneValue):
        """
        :type stoneValue: List[int]
        :rtype: str
        """
        n = len(stoneValue)
        suffixSum = [0 for _ in range(n+1)]
        dp = [0 for _ in range(n+1)]
        for i in range(n-1, -1, -1):
            suffixSum[i] = suffixSum[i+1] + stoneValue[i]
        for i in range(n-1, -1, -1):
            dp[i] = stoneValue[i] + suffixSum[i+1] - dp[i+1]
            for k in range(i+1, min(n, i+3)):
                dp[i] = max(dp[i], suffixSum[i] - dp[k+1])
        if dp[0]*2 == suffixSum[0]:
            return "Tie"
        elif dp[0]*2 > suffixSum[0]:
            return "Alice"
        else:
            return "Bob"
