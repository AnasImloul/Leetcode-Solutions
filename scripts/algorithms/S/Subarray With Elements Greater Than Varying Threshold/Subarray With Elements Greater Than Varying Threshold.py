# Runtime: 3127 ms (Top 12.36%) | Memory: 28.8 MB (Top 64.23%)
class Solution:
    def validSubarraySize(self, nums: List[int], threshold: int) -> int:
        nums = [0] + nums + [0]
        stack = [0]
        for i in range(1,len(nums)):
            while nums[i] < nums[stack[-1]]:
                tmp = nums[stack.pop()]
                if tmp > threshold / (i - stack[-1] - 1):
                    return i - stack[-1] - 1
            stack.append(i)
        return -1