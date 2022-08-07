class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        @cache
        def dfs(i, sum_):
            if i == len(nums):
                if sum_ == target: return 1
                else: return 0
            return dfs(i+1, sum_+nums[i]) + dfs(i+1, sum_-nums[i])
        if abs(target) > sum(nums): return 0
        return dfs(0, 0)
