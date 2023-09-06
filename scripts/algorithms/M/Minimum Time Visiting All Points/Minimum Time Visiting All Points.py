# Runtime: 38 ms (Top 57.7%) | Memory: 13.27 MB (Top 67.6%)

class Solution:
    def minTimeToVisitAllPoints(self, points):
        res = 0
        n = len(points)
        for i in range(n-1):
            dx = abs(points[i+1][0]-points[i][0])
            dy = abs(points[i+1][1]-points[i][1])
            res+= max(dx,dy)
        return res

            
obj = Solution()
print(obj.minTimeToVisitAllPoints([[1,1],[3,4],[-1,0]]))