class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        ans = 0
        n = len(points)
        
        for i in range(n):
            d = collections.defaultdict(int)
            for j in range(n):
                if i != j:
                    slope = float("inf")
                    if (points[j][1] - points[i][1] != 0):
                        slope = (points[j][0] - points[i][0]) / (points[j][1] - points[i][1])
                    d[slope] += 1
            if d:
                ans = max(ans, max(d.values())+1)
            else:
                ans = max(ans, 1)
        
        return ans