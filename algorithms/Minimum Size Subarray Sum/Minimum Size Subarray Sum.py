class Solution:
    def minSubArrayLen(self, target, nums):
		# Init left pointer and answer
        l, ans = 0, len(nums) + 1
		# Init sum of subarray
        s = 0 
		# Iterate through all numbers as right subarray 
        for r in range(len(nums)):
			# Add right number to sum
            s += nums[r]
			# Check for subarray greater than or equal to target
            while s >= target:
				# Calculate new min
                ans = min(ans, r - l + 1)
				# Remove current left nubmer from sum
                s -= nums[l]
				# Move left index up one
                l += 1
		# No solution
        if ans == len(nums) + 1:
            return 0
		# Solution
        return ans 
