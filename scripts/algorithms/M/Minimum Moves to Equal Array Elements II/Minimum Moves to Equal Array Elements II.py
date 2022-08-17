class Solution:
	def minMoves2(self, nums: List[int]) -> int:
		nums.sort()
		n = len(nums)
		m = n//2
		median = nums[m]

		ans = 0
		for num in nums:
			ans += abs(num-median)
		return ans