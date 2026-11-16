# Runtime: 982 ms (Top 9.32%) | Memory: 64.60 MB (Top 21.19%)

class Solution:
    def solve(self, nums, x, i, p, dp) -> int:
        if i > len(nums) - 1:
            return 0

        if dp[i][p] != -1:
            return dp[i][p]

        y = nums[i] % 2
        if p == y:
            include = nums[i] + self.solve(nums, x, i + 1, y, dp)
        else:
            include = nums[i] - x + self.solve(nums, x, i + 1, y, dp)

        exculde = self.solve(nums, x, i + 1, p, dp)

        dp[i][p] = max(include,exculde)
        return dp[i][p]

    def maxScore(self, nums: List[int], x: int) -> int:
        p = nums[0] % 2
        n = len(nums)
        dp = [[-1 for _ in range(2)] for _ in range(n)]
        return nums[0] + self.solve(nums, x, 1, p, dp)
