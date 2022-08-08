class Solution:
    def canTransform(self, start: str, end: str) -> bool:
        def chars(s):
            for i, c in enumerate(s):
                if c != 'X':
                    yield i, c
            
            yield -1, ' '
        
        for (startI, startC), (endI, endC) in zip(chars(start), chars(end)):
            if (startC != endC or
                (startC == 'L' and startI < endI) or
                (startC == 'R' and startI > endI)):
                return False
        
        return True