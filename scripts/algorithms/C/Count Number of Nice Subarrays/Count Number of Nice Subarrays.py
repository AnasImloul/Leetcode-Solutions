class Solution:
	def numberOfSubarrays(self, arr, k):
		# the difference gives the exact K elements count
		return self.atMostKElements(arr, k) - self.atMostKElements(arr, k-1)

	def atMostKElements(self, arr, k):
		i, j = 0, 0
		res, curr_window_count = 0, 0
		for j in range(len(arr)):
			# the {condition} which increases the curr_window_count. Different for different problems
			if arr[j]%2 != 0: curr_window_count += 1

			# check if the window is valid. If its invalid, make it valid by shortening the left pointer.
			# Valid is when curr_window_count <= k (at most K elements)
			if curr_window_count > k:
				while curr_window_count > k:
					# this condition will be specific to the problem
					if arr[i]%2 != 0: curr_window_count -= 1
					i += 1

			# total nos of elements in the valid window is added to the res. 
			# eg: [1, 2, 3], if this is the valid window, then [3], [2,3], [1,2,3] are all valid for solving at most K elements problem.
			res += j-i+1
			j += 1
		return res