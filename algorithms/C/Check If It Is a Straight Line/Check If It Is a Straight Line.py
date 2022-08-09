class Solution(object):
    def checkStraightLine(self, coordinates):
        """
        :type coordinates: List[List[int]]
        :rtype: bool
        """
        if len(coordinates) == 2:
            return True
        
        num = coordinates[1][1] - coordinates[0][1]
        den = coordinates[1][0] - coordinates[0][0]
        
        for i in range(2, len(coordinates)):
            if num * (coordinates[i][0] - coordinates[0][0]) != den * (coordinates[i][1] - coordinates[0][1]):
                return False
        
        return True
