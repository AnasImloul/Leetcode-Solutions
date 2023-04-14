class Solution:
    def minimumSum(self, num: int) -> int:


        nums=[int(ch) for ch in str(num)]

        nums.sort()

        val1=int(str(nums[0]) + str(nums[-1]))
        val2=int(str(nums[1]) + str(nums[2]))

        return val1+val2
        