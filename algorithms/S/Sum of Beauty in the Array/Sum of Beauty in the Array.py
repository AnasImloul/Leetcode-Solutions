class Solution:
    def sumOfBeauties(self, nums: List[int]) -> int:
        n = len(nums)
        max_dp = [0] * n
        min_dp = [float(inf)] * n
        max_dp[0] = nums[0]
        min_dp[-1] = nums[-1]
        
        for i in range(1, n):
            max_dp[i] = max(nums[i], max_dp[i-1])
            
        for i in range(n-2, -1, -1):
            min_dp[i] = min(nums[i], min_dp[i+1])
        
        ans = 0
        for i in range(1, n-1):
            if max_dp[i-1] < max_dp[i] and nums[i] < min_dp[i+1]:
                ans += 2
            elif nums[i-1] < nums[i] < nums[i+1]:
                ans += 1
        return ans
