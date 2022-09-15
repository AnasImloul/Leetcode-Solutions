# Runtime: 239 ms (Top 76.52%) | Memory: 14.6 MB (Top 25.99%)

class Solution:
    def countGoodRectangles(self, rectangles: List[List[int]]) -> int:

        #Runtime: 184 ms, faster than 65.71% of Python3 online submissions
        #Memory Usage: 14.9 MB, less than 39.90% of Python3 online submissions

        res = []

        minSide = 0
        maxLen = 0

        for l, w in rectangles:

            minSide = min(l, w) #Gets minSide of each rectangle

            if minSide > maxLen: #Checks if rectangle holds new maxLen
                maxLen = minSide #Tracks the current maxLen

            res.append(minSide) #Holds each rectangles minSIde

        return res.count(maxLen)#Returns the count of rectangles whos minSide is equal to maxLen
