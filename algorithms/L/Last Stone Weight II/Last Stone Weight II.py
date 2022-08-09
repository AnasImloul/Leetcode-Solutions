class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        if len(stones) == 1: return stones[0]
        total = sum(stones)
        half, leng =  total// 2, len(stones)
        dp = [[0] *  (half + 1) for _ in  range(leng + 1)]
        
        for i in range(1, leng+1):
            for j in range(1, half+1):
                if j - stones[i-1] >= 0:
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j - stones[i-1]] + stones[i-1])
                else:
                    dp[i][j] = dp[i-1][j]
        return total - 2 * dp[leng][half]
