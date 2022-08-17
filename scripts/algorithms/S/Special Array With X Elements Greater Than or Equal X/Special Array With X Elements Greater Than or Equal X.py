class Solution:
    def specialArray(self, nums: List[int]) -> int:
        nums.sort()
        l, r = 0, len(nums) - 1
        while l <= r:
            m = l + (r - l) // 2
            x = len(nums) - m
            if nums[m] >= x:
                if m == 0 or nums[m - 1] < x:
                    return x
                else:
                    r = m - 1
            else:
                l = m + 1
        return -1
