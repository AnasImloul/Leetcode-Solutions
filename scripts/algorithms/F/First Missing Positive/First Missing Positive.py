# Runtime: 295 ms (Top 90.42%) | Memory: 28 MB (Top 72.11%)
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        mn = float('inf')
        mx = 0
        numsSet = set()

        for i in range(len(nums) - 1, -1, -1):
            if nums[i] > 0:
                if nums[i] < mn:
                    mn = nums[i]
                if nums[i] > mx:
                    mx = nums[i]
                numsSet.add(nums[i])
            del nums[i]

        if mn >= 2:
            return 1
        if len(numsSet) == mx:
            return mx + 1
        for i in range(2, len(numsSet) + 1):
            if i not in numsSet:
                return i