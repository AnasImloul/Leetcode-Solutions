class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total = sum(nums)
        if total % 2: return False
        total //= 2
        leng = len(nums)
        dp = [[False] * (total + 1) for _ in range(leng + 1)]
        
        for i in range(leng + 1): dp[i][0] = True
        for i in range(1, leng + 1):
            for j in range(1, total + 1):
                dp[i][j] = dp[i-1][j]
                if j - nums[i-1] >= 0:
                    dp[i][j] |= dp[i-1][j-nums[i-1]] 
        return dp[leng][total]
