# Runtime: 150 ms (Top 9.30%) | Memory: 13.9 MB (Top 38.82%)
class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        prev_x, prev_y = points[0]
        output = 0
        for cur_x, cur_y in points[1:]:
            output+=max(abs(cur_x-prev_x), abs(cur_y-prev_y))
            prev_x, prev_y = cur_x, cur_y
        return output