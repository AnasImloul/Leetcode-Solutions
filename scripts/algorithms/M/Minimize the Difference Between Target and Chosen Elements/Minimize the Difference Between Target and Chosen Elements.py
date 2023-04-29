class Solution:
    def minimizeTheDifference(self, mat: List[List[int]], target: int) -> int:
        min_possible = sum(min(row) for row in mat)
        if min_possible >= target: return min_possible - target
        curs = {0}
        for row in mat:
            curs = {x + y for x in row for y in curs if x + y <= 2*target}
        return min(abs(target - x) for x in curs)