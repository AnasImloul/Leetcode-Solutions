# Runtime: 1321 ms (Top 44.04%) | Memory: 28.7 MB (Top 24.77%)
class Solution:
    def maxRunTime(self, n: int, batteries: List[int]) -> int:
        batteries.sort()
        total=sum(batteries)
        while batteries[-1]>total//n:
            n-=1
            total-=batteries.pop()
        return total//n