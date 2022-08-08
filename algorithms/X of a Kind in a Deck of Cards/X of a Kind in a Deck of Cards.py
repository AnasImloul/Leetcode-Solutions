from collections import Counter
from math import gcd
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        vals = Counter(deck).values()
        return reduce(gcd, vals) >= 2