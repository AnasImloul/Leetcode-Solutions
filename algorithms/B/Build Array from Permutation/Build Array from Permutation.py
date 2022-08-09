class Solution:
	#As maximum value of the array element is 1000, this solution would work
    def buildArray(self, nums: List[int]) -> List[int]:
        for i in range(len(nums)):            
            if nums[nums[i]] <= len(nums):
                nums[i] = nums[nums[i]] * 1000 + nums[i]
            else:
                nums[i] = mod(nums[nums[i]],1000) * 1000 + nums[i]
            
        for i in range(len(nums)):
            nums[i]  = nums[i] // 1000
            
        return nums
