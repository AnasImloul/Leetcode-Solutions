class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        psum = {0:-1}
        currentSum = 0
        for i in range(len(nums)):
            currentSum += nums[i]
            remainder = currentSum % k
            if remainder not in psum:
                psum[remainder] = i
            else:
                if i - psum[remainder] > 1:
                    return True
        return False
