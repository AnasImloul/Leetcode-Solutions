class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        steps = 0
        for i in range(len(points)-1):
            point = points[i]
            next_point = points[i+1]
            steps += max(abs(next_point[0] - point[0]), abs(next_point[1] - point[1]))
        return steps