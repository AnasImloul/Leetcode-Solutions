class Solution:
    def addRungs(self, rungs: List[int], dist: int) -> int:
        return sum((a - b - 1) // dist for a, b in zip(rungs, [0] + rungs))
