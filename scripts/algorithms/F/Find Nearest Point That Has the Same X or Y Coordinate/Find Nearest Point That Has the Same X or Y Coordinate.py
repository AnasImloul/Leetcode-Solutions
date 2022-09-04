# Runtime: 689 ms (Top 99.93%) | Memory: 19.5 MB (Top 5.79%)
class Solution:
    def nearestValidPoint(self, x: int, y: int, points: List[List[int]]) -> int:
        minDist = math.inf
        ans = -1
        for i in range(len(points)):
            if points[i][0]==x or points[i][1]==y:
                manDist = abs(points[i][0]-x)+abs(points[i][1]-y)
                if manDist<minDist:
                    ans = i
                    minDist = manDist
        return ans
