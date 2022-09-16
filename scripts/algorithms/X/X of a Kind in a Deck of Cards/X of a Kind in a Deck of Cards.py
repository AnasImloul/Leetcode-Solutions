# Runtime: 274 ms (Top 25.71%) | Memory: 14.2 MB (Top 95.43%)
from collections import Counter
from math import gcd
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        vals = Counter(deck).values()
        return reduce(gcd, vals) >= 2