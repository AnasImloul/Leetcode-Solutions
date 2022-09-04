# Runtime: 250 ms (Top 81.05%) | Memory: 16.2 MB (Top 5.39%)
#lets start adding elements to stack. We have to fin the min length [a, b] interval (corresponding to the problem description).
# a has to be the first element's index we pop from the array. lets say y is the last element's index we pop.
# and max_pop is the maximum element(not index) we pop during stacking.After stacking process is done we are going to have
#last elements in the stack E(E is the stack after stacking is done).We have to find M = maximum_element(max_pop, all elements of E)
#Index of M is going to be right edge of the [a, b] interval

class Solution:
    def findUnsortedSubarray(self, nums) -> int:
        stack = []
        min_index = len(nums)
        max_index = 0
        max_pop = float('-inf')
        for i in range(len(nums)):
            while stack and nums[i] < stack[-1][0]:

                p = stack.pop()
                if p[0] > max_pop:
                    max_pop = p[0]
                if p[1] < min_index:
                    min_index = p[1]
                if p[1] > max_index:
                    max_index = p[1]
            stack.append([nums[i], i])
        max_r = max_index
        for st in stack:
            if st[0] < max_pop:
                max_r = st[1]
        if min_index == len(nums):
            return 0
        return max_r - min_index +1
