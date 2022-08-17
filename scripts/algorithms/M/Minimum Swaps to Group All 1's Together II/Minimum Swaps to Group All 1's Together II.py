class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        width = sum(num == 1 for num in nums) #width of the window
        nums += nums
        res = width
        curr_zeros = sum(num == 0 for num in nums[:width]) #the first window is nums[:width]
        
        for i in range(width, len(nums)):
            curr_zeros -= (nums[i - width] == 0) #remove the leftmost 0 if exists
            curr_zeros += (nums[i] == 0) #add the rightmost 0 if exists
            res = min(res, curr_zeros) #update if needed
        
        return res
