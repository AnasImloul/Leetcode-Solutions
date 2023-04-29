class Solution:
    # two pointer
    def maximizeGreatness(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        ptr1 = ptr2 = 0
        count = 0

        while ptr2 < n:
            if nums[ptr1] < nums[ptr2]:
                ptr1 += 1                
                count += 1
            ptr2 += 1
        return count
        