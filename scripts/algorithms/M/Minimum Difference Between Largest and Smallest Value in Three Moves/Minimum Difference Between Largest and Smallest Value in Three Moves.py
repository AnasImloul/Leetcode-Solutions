# Runtime: 942 ms (Top 5.03%) | Memory: 24.7 MB (Top 96.65%)
class Solution:
    def minDifference(self, nums: List[int]) -> int:
        if len(nums) <= 3:
            return 0

        nums.sort()
        t1 = nums[-1] - nums[3]
        t2 = nums[-4] - nums[0]
        t3 = nums[-2] - nums[2]
        t4 = nums[-3] - nums[1]

        return min(t1,t2,t3,t4)