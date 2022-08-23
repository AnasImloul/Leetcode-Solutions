# Runtime: 2938 ms (Top 61.69%) | Memory: 14.1 MB (Top 97.87%)
class Solution:
    def countPoints(self, points: List[List[int]], queries: List[List[int]]) -> List[int]:
        return [sum(math.sqrt((x0-x1)**2 + (y0-y1)**2) <= r for x1, y1 in points) for x0, y0, r in queries]