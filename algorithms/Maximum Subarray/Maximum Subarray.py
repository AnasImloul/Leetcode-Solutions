class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxSum = max(nums)
        currSum = 0
        for i in range(len(nums)):
            currSum = currSum + nums[i]
            if currSum > maxSum:
                maxSum = currSum
            if currSum < 0:
                currSum = 0
        return maxSum
