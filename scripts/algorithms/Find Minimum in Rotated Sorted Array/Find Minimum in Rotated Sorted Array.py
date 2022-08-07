class Solution:
    def findMin(self, nums: List[int]) -> int:
        if len(nums) == 1 or nums[0] < nums[-1]:
            return nums[0]
        
        l, r = 0, len(nums) - 1
        
        while l <= r:
            mid = l + (r - l) // 2
            
            if mid > 0 and nums[mid - 1] > nums[mid]:
                return nums[mid]
            
			# We compare the middle number and the right index number
			# but why we cannot compare it with the left index number?
            if nums[mid] > nums[r]:
                l = mid + 1
            else:
                r = mid - 1
