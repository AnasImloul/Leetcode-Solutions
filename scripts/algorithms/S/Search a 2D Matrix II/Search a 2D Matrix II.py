# Runtime: 121 ms (Top 76.1%) | Memory: 19.55 MB (Top 13.9%)

class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        found=False
        for X in matrix:
             for M in X:
                if M==target:
                    found=True
        return found