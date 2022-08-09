#Baraa
class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        i = 0
        res = 0
        for j in range(len(nums)):
            if nums[j] != 0:
                i = j + 1
            else:
                res += (j - i + 1)
        return res
