# Runtime: 962 ms (Top 100.00%) | Memory: 36.9 MB (Top 93.24%)
from bisect import bisect_left
class Solution:
    def minOperations(self, target: List[int], arr: List[int]) -> int:
        dt = {num: i for i, num in enumerate(target)}
        stack = []
        for num in arr:
            if num not in dt: continue
            i = bisect_left(stack, dt[num])
            if i == len(stack):
                stack.append(dt[num])
            else:
                stack[i] = dt[num]
        return len(target) - len(stack)