class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        for i in range(len(nums)-1, 0, -1):
            if nums[i] > nums[i-1]:
                
                min_index = i
                curr_min = nums[i]
                for j in range(i+1, len(nums)):
                    if nums[j] < nums[i] and nums[j] > nums[i-1]:
                        min_index = j
                
                nums[i-1], nums[min_index] = nums[min_index], nums[i-1]
                
                nums[i:] = sorted(nums[i:])
                break
        else:
            nums[:] = nums[::-1]
