class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if len(nums) == 0:
            return [-1, -1]
        #Idea: Similar to the "first bad version" question. But this time, we need two pivots, one is to find the first target number in the list, one is to find the last target number in the list
        index1 = -1
        index2 = -1
        #First find the first
        left = 0
        right = len(nums)-1
        while (right - left >1):
            mid = (right+left)//2
            if nums[mid]<target:
                left = mid + 1
            elif nums[mid]>=target:
                right = mid
        if nums[right] == target:
            index1 = right
        if nums[left] == target:
            index1 = left
        if nums[left] != target and nums[right] != target:
            index1 = index2 = -1
            return [index1, index2]
        #Second find the last
        index2 = -1
        left = index1
        right = len(nums)-1
        while (right - left > 1):
            mid = (right+left)//2
            if nums[mid]<=target:
                left = mid
            elif nums[mid]>target:
                right = mid
        if nums[left] == target:
            index2 = left
        if nums[right] == target:
            index2 = right
        if nums[left] != target and nums[right] != target:
            return [index1, index2]
        return [index1, index2]
            
