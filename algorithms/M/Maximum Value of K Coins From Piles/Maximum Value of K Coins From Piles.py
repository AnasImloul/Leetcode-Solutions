class Solution:
    def maxValueOfCoins(self, piles: List[List[int]], k: int) -> int:
        n = len(piles)
        prefixSum = []
        for i in range(n):
            temp = [0]
            for j in range(len(piles[i])):
                temp.append(temp[-1] + piles[i][j])
            prefixSum.append(temp)
            
        dp = [[0] * (k + 1) for _ in range(n)]
        for j in range(1, k + 1):
            if j < len(prefixSum[0]):
                dp[0][j] = prefixSum[0][j]
        
        for i in range(1, n):
            for j in range(1, k + 1):
                for l in range(len(prefixSum[i])):
                    if l > j:
                        break
                    dp[i][j] = max(dp[i][j], prefixSum[i][l] + dp[i - 1][j - l])
        return dp[n - 1][k]
