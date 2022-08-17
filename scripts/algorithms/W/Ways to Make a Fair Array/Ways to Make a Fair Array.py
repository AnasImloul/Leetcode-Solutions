class Solution:
	def waysToMakeFair(self, nums: List[int]) -> int:
		if len(nums) == 1:
			return 1

		if len(nums) == 2:
			return 0

		prefixEven = sum(nums[2::2])
		prefixOdd = sum(nums[1::2])
		result = 0

		if prefixEven == prefixOdd and len(set(nums)) == 1:
			result += 1

		for i in range(1,len(nums)):
			if i == 1:
				prefixOdd, prefixEven = prefixEven, prefixOdd 

			if i > 1:
				if i % 2 == 0:
					prefixEven -= nums[i-1]
					prefixEven += nums[i-2]

				else:
					prefixOdd -= nums[i-1]
					prefixOdd += nums[i-2]

			if prefixOdd == prefixEven:
				result += 1

		return result
