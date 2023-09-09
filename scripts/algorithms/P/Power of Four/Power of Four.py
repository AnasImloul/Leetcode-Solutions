# Runtime: 46 ms (Top 35.3%) | Memory: 16.23 MB (Top 61.5%)

import math 
class Solution:
    def isPowerOfFour(self, n: int) -> bool:

        if n <= 0:
            return False
        return math.log(n, 4).is_integer()