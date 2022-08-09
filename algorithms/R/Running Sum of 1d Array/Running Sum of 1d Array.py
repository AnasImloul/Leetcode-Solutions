class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        output, add = [], 0
        for num in nums:
            add += num
            output.append(add)
        return output
