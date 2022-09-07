# Runtime: 170 ms (Top 20.15%) | Memory: 15 MB (Top 44.78%)
from itertools import accumulate
class Solution:
    def findMinMoves(self, machines: List[int]) -> int:
        n = len(machines)
        summation = sum(machines)
        if summation%n:
            return -1
        avg = summation//n
        left = list(accumulate(machines))
        result = 0
        for i in range(n):
            move_to_right = max(left[i] - (i+1)*avg, 0)
            move_to_left = max(left[-1]-(left[i-1] if i!=0 else 0) - (n-i)*avg, 0)
            result = max(result, move_to_right + move_to_left)
        return result
