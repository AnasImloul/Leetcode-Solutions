class Solution:
	def minimumDeviation(self, nums: List[int]) -> int:

		from sortedcontainers import SortedList

		for i in range(len(nums)):

			if nums[i]%2!=0:
				nums[i]=nums[i]*2

		nums = SortedList(nums)

		result = 100000000000

		while True:
			min_value = nums[0]
			max_value = nums[-1]

			if max_value % 2 == 0:
				nums.pop()
				nums.add(max_value // 2)
				max_value = nums[-1]
				min_value = nums[0]

				result = min(result , max_value - min_value)
			else:
				result = min(result , max_value - min_value)
				break

		return result
