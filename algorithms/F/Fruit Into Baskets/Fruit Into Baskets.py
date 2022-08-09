class Solution:
	def totalFruit(self, nums: List[int]) -> int:
		"""
		This problem asks us to find the maximum length of a subarray, 
		which has maximum 2 unique numbers.
		I changed the input "fruit -> nums" for easy typing.
		"""
		#Define the budget k we can spend
		k = 2
		left = 0
		hashmap = {}

		for right in range(len(nums)):

			# when we meet a new unique number, 
			# add it to the hashmap and lower the budget
			if nums[right] not in hashmap:
				k -= 1
				hashmap[nums[right]] = 1

			# when we meet a number in our window
			elif nums[right] in hashmap:
				hashmap[nums[right]] += 1

			# when we exceed our budget
			if k < 0:
				# when we meet a number that can help us to save the budget
				if hashmap[nums[left]] == 1:
					del hashmap[nums[left]]
					k += 1
				# otherwise we just reduce the freq
				else:
					hashmap[nums[left]] -= 1
				left += 1

		"""
		We never shrink our window, we just expand the window when it satisfies the condition
		So, finally the window size is the maximum
		"""        
		return right - left + 1
