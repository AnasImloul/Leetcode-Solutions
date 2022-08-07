import math
class Solution(object):
    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        allowedDiffs = [int(1*math.pow(2,i)) for i in range(0,n)]
        grayCodes = [0]
        for diff in allowedDiffs:
            grayCodes += [code + diff for code in reversed(grayCodes)]
        return grayCodes
