# Runtime: 1574 ms (Top 5.27%) | Memory: 22.4 MB (Top 17.30%)
class Solution:
    def numSubarrayBoundedMax(self, nums: List[int], left: int, right: int) -> int:
        n = len(nums)
        stack = []
        next_greater = [n] * n
        prev_greater = [-1] * n
        for i in range(n):
            while len(stack) > 0 and nums[i] > nums[stack[-1]]:
                curr = stack.pop()
                next_greater[curr] = i
            if len(stack) > 0:
                prev_greater[i] = stack[-1]
            stack.append(i)
        res = 0
        for i in range(n):
            if left <= nums[i] <= right:
                l = prev_greater[i]
                r = next_greater[i]
                res += (i - l) * (r - i)
        return res