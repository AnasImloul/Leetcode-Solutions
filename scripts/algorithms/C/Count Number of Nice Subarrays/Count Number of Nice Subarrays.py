# Runtime: 628 ms (Top 69.2%) | Memory: 18.88 MB (Top 60.5%)

class Solution(object):
	def numberOfSubarrays(self, nums, k):
		"""
		e.g. k = 2
		nums = [2, 2, 1, 2, 1, 2, 2]
		index=  0  1  2  3  4  5  6
		2 even numbers to left of first 1
		2 even numbers to right of last 1
		total number of subarrays = pick between 0-2 numbers on left, then, pick between 0-2 numbers on right
		i.e (left+1)  (right+1)
		Then slide window to next set of 2 odd numbers
		"""

		odds = []

		for i in range(len(nums)):
			if nums[i] & 1:
				odds.append(i)                      #' Find index of all odd numbers '

		odds = [-1] + odds + [len(nums)]            #' Handle edge cases '
		nice = 0

		for i in range(1, len(odds)-k):
			left = odds[i] - odds[i-1] - 1          #' Number of 'left' even numbers '
			right = odds[i+k] - odds[i+k-1] - 1     #' Number of 'right' even numbers '
			nice += (left+1)*(right+1)              #' Total sub-arrays in current window '

		return nice
    