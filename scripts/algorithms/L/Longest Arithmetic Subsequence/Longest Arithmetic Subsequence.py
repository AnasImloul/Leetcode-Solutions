# Runtime: 7591 ms (Top 12.82%) | Memory: 21.8 MB (Top 96.69%)
class Solution:
    def longestArithSeqLength(self, nums: List[int]) -> int:
        dp = [[1]*1001 for i in range(len(nums))]
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                d = nums[j] - nums[i] + 500
                dp[j][d] = max(dp[i][d]+1,dp[j][d])
        return max([max(i) for i in dp])