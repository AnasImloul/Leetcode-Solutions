// Runtime: 796 ms (Top 99.64%) | Memory: 29.60 MB (Top 94.86%)

class Solution:
	def maximumUniqueSubarray(self, nums: List[int]) -> int:
		low = 0
		visited = set()
		result = 0
		curSum = 0
		for high in range(len(nums)):
			while nums[high] in visited:
				visited.remove(nums[low])
				curSum -= nums[low]
				low+=1

			visited.add(nums[high])
			curSum += nums[high]

			if curSum > result:
				result = curSum

		return result
