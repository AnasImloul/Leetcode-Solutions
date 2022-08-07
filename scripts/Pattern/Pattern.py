class Solution(object):
    def find132pattern(self, nums):
        # Base Condition...
        if len(nums) < 3:
            return False
        m = float('-inf')
        # Initialise a empty stack...
        stack = []
        # Run a Loop from last to first index...
        for i in range(len(nums)-1, -1, -1):
            # If m is greater than nums[i], return true...
            if nums[i] < m:
                return True
            # If stack is not empty &  nums[i] is greater than the top element of stack, then pop the element...
            else:
                while stack and stack[-1] < nums[i]:
                    m = stack.pop()
            # Otherwise, append nums[i] into stack...
            stack.append(nums[i])
        # If the condition is not satisfied, return false.
        return False
