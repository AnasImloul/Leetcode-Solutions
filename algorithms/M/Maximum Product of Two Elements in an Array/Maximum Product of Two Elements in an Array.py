class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        # mx1 - max element, mx2 - second max element
        mx1 = nums[0] if nums[0] > nums[1] else nums[1]
        mx2 = nums[1] if nums[0] > nums[1] else nums[0]
        for num in nums[2:]:
            if num > mx1:
                mx1, mx2 = num, mx1
            elif num > mx2:
                mx2 = num

        return (mx1 - 1) * (mx2 - 1)

