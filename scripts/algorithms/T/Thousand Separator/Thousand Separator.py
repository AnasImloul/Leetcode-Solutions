class Solution:
	def thousandSeparator(self, n: int) -> str:
		nums = str(n)
		count = 0
		result = ""
		i = len(nums)-1

		while i >= 0:
			result = nums[i] + result
			count +=1

			if count == 3 and i != 0:
				count = 0
				result = "." + result
			i-=1
		return result