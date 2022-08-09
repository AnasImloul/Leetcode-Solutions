class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        pair_sum = []
        nums.sort()
        for i in range(len(nums)//2):
            pair_sum.append(nums[i]+nums[len(nums)-i-1])
        return max(pair_sum)
