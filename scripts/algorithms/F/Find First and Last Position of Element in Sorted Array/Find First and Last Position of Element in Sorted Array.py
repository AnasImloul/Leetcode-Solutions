class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        # if target is not in nums list, we simply return [-1,-1]
		if target not in nums:
            return [-1,-1]
        
		# create an empty list
        result = []
		# iterate nums for the first time, if we found nums[i] matches with target
		# append the index i to result, break the for loop
		# because we only care the first and last index of target in nums
        for i in range(len(nums)):
            if nums[i] == target:
                result.append(i)
                break
        
		# loop through nums backward, if we found nums[j] matches target
		# append j to result and break the for loop
        for j in range(len(nums)-1, -1, -1):
            if nums[j] == target:
                result.append(j)
                break
        
        return result
		
		
