class Solution:
    def minSumOfLengths(self, arr: List[int], target: int) -> int:
        l, windowSum, res = 0, 0, float('inf')
        min_till = [float('inf')] * len(arr) # records smallest lenth of subarry with target sum up till index i.
        for r, num in enumerate(arr): # r:right pointer and index of num in arr
            windowSum += num
            while windowSum > target: 
			# when the sum of current window is larger then target, shrink the left end of the window one by one until windowSum <= target
                windowSum -= arr[l]
                l += 1
			# the case when we found a new target sub-array, i.e. current window
            if windowSum == target:
			   # length of current window
                curLen = r - l + 1
				# min_till[l - 1]: the subarray with min len up till the previous position of left end of the current window: 
				# avoid overlap with cur window
				# new_sum_of_two_subarray = length of current window + the previous min length of target subarray without overlapping
				# , if < res, update res.
                res = min(res, curLen + min_till[l - 1])
				# Everytime we found a target window, update the min_till of current right end of the window, 
				# for future use when sum up to new length of sum_of_two_subarray and update the res.
                min_till[r] = min(curLen, min_till[r - 1])
            else:
			# If windowSum < target: window with current arr[r] as right end does not have any target subarry, 
			# the min_till[r] doesn't get any new minimum update, i.e it equals to previous min_till at index r - 1. 
                min_till[r] = min_till[r - 1]
        return res if res < float('inf') else -1
	
Time = O(n): when sliding the window, left and right pointers traverse the array once.
Space = O(n): we use one additional list min_till[] to record min length of target subarray till index i.