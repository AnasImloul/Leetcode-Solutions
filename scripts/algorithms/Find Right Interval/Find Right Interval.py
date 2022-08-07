class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        leftEnds = sorted((a, i) for i, (a, b) in enumerate(intervals))
        
        rightIntervalIndexes = [-1] * len(intervals)
        for i, (a, b) in enumerate(intervals):
            searchResult = bisect_left(leftEnds, b, key = lambda x: x[0])
            if searchResult < len(intervals):
                rightIntervalIndexes[i] = leftEnds[searchResult][1]
                
        return rightIntervalIndexes
