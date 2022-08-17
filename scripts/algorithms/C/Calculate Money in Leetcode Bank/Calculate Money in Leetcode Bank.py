from itertools import cycle, \
                      repeat, \
                      starmap
from operator import floordiv


class Solution:
    def totalMoney(self, n: int) -> int:
        return sum(starmap(add,zip(
            starmap(floordiv, zip(range(n), repeat(7, n))),
            cycle((1,2,3,4,5,6,7))
        )))

