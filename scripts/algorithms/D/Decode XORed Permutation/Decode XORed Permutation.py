# Runtime: 1921 ms (Top 32.18%) | Memory: 33.8 MB (Top 16.09%)

from functools import reduce
from operator import xor

class Solution:

    def decode(self, encoded: List[int]) -> List[int]:
        n = len(encoded) + 1
        a = reduce(xor, range(1, n+1))
        b = reduce(xor, encoded[1::2])
        result = [a ^ b]
        for y in encoded:
            result.append(result[-1] ^ y)
        return result