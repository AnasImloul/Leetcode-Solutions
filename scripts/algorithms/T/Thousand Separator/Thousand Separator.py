# Runtime: 17 ms (Top 24.0%) | Memory: 13.24 MB (Top 48.1%)

class Solution(object):
    def thousandSeparator(self, n):
        """
        :type n: int
        :rtype: str
        """
        n = str(n)
        if len(n) <= 3:
            return str(n)
        result = ""      
        dot = '.'
        index = 0
        startPos = len(n) % 3 
        if startPos == 0:
            startPos += 3
        val = -1
        while index < len(n):
            result += n[index]
            if index == startPos - 1:
                result += dot
                val = 0
            if val != -1:
                val += 1
                if val > 3 and (val - 1) % 3 == 0 and index != len(n) - 1:
                    result += dot
                    val = 1  
            index += 1

        return result