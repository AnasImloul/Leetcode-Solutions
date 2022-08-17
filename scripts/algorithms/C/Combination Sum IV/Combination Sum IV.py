class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        dp = [0] * (target+1)
        dp[0] = 1
        for i in range(1, target+1):
            for num in nums: 
                num_before = i - num
                if num_before >= 0:
                    dp[i] += dp[num_before]
        return dp[target]
