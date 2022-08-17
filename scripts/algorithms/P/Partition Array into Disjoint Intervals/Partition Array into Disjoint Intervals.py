class Solution:
    def partitionDisjoint(self, nums: List[int]) -> int:
        prefix = [nums[0] for _ in range(len(nums))]
        suffix = [nums[-1] for _ in range(len(nums))]
        for i in range(1, len(nums)):
            prefix[i] = max(prefix[i-1], nums[i-1])
        for i in range(len(nums)-2, -1, -1):
            suffix[i] = min(suffix[i+1], nums[i+1])
        for i in range(0, len(nums)-1):
            if prefix[i] <= suffix[i]:
                return i+1
