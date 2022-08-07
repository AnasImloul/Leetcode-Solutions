class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        sz, dp, ans = len(nums), [defaultdict(int) for _ in range(len(nums))], 0
        for i in range(1, sz):
            for j in range(i):
                difference = nums[i] - nums[j]
                dp[i][difference] += 1
                if difference in dp[j]:
                    dp[i][difference] += dp[j][difference]
                    ans += dp[j][difference]
        return ans
