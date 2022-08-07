class Solution:
    """
    we can solve this problem using binary search
    """
    def findPeakElement(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return 0
        def search(low, high, nums):
            mid = (low + high) // 2
            if mid == 0: 
                if nums[mid] < nums[mid+1]:
                    return search(mid+1, high, nums)
                else:
                    return mid
                
            elif mid == len(nums)-1:
                if nums[mid] < nums[mid-1]:
                    # goto left
                    return search(low, mid-1, nums)
                else:
                    return mid
                
            elif nums[mid] < nums[mid-1]:
                # goto left
                return search(low, mid-1, nums)
            elif nums[mid] < nums[mid+1]:
                # goto right
                return search(mid+1, high, nums)
            return mid
