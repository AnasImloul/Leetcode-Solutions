class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        def str2seconds(x):
            h, m = x.split(':')
            return int(h) * 60 + int(m)
        
        def getDifference(a, b):
            
            return min(b - a, 24 * 60 - b + a)
        
        timePoints = map(str2seconds, timePoints)
        timePoints = sorted(timePoints)
        
        n = len(timePoints)
        result = 2 ** 31
        for i in range(n - 1):
            result = min(result, getDifference(timePoints[i], timePoints[i + 1]))
        result = min(result, getDifference(timePoints[0], timePoints[-1]))
        
        return result
