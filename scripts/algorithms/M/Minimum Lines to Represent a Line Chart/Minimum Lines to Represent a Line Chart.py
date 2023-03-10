from fractions import Fraction
from itertools import pairwise
from math import inf
from operator import itemgetter

Point = tuple[int, int]


class Solution:
    def minimumLines(self, prices: list[Point]) -> int:
        if len(prices) == 1:
            return 0
        else:
            prices.sort(key=itemgetter(0))

            return self.using_slope(prices)
            # return self.using_cross_product(prices)

    @staticmethod
    def using_slope(prices: list[Point]) -> int:
        output, slope = 1, Solution.dy_by_dx

        ab = next(pairs := pairwise(prices))

        for bc in pairs:
            if slope(ab) != slope(bc):
                output += 1

            ab = bc

        return output

    @staticmethod
    def dy_by_dx(ab: tuple[Point, Point]) -> float | Fraction:
        (x1, y1), (x2, y2) = ab

        dx, dy = x2 - x1, y2 - y1

        if dx == 0:
            # 1. dx is 0, it means we have a vertical line going from (x1, y1). So whether dy is positive or
            #    negative, it does not matter
            # 2. infinity can not be represented by fraction module so returning it directly from math module
            return inf
        else:
            # To avoid floating point error, we use fraction module.

            # (Simple divisions can give same results for example (apparently one of the test cases),
            # 499999998/499999999 and 499999999/500000000 gives same result, and that is where Fraction
            # class shines)
            return Fraction(dy, dx)

    @staticmethod
    def using_cross_product(prices: list[Point]) -> int:
        output, on_line = 1, Solution.lie_on_same_line

        a = next(itr := iter(prices))

        for b, c in pairwise(itr):
            if not on_line(a, b, c):
                output += 1

            a = b

        return output

    @staticmethod
    def lie_on_same_line(a: Point, b: Point, c: Point) -> bool:
        (x1, y1), (x2, y2), (x3, y3) = a, b, c

        return (y2 - y1) * (x3 - x2) == (x2 - x1) * (y3 - y2)