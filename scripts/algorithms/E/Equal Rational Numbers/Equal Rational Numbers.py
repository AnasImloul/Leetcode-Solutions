// Runtime: 69 ms (Top 5.88%) | Memory: 14 MB (Top 23.53%)
class Solution:
    # inspired from:
    # https://coolconversion.com/math/recurring-decimals-as-a-fraction/
    # to which we wouldn't have access during interview.

    import typing
    def isRationalEqual(self, s: str, t: str) -> bool:

        # intuition:
        # write each numbes as fraction: num / den
        # then compare the two fractions.

        num1, den1 = self.toFraction(s)
        num2, den2 = self.toFraction(t)

        return den1 * num2 == den2 * num1

    def toFraction(self, s: str) -> typing.Tuple[int, int]:
        if "." not in s:
            return int(s), 1

        intp, frac = s.split(".")
        # decimal dot, but no repeating part:
        # xyz.abc = xyzabc / 1000
        if "(" not in frac:
            ifrac = int(frac) if len(frac) > 0 else 0
            num = int(intp) * (10 ** len(frac)) + ifrac
            den = 10 ** len(frac)
            return num, den

        # this is for cases like a.b(c)
        # let n = a.b(c)
        # then, 10^(len(b+c)) * n = abc.(c)
        # and 10^(len(b)) * n = ab.(c)
        # subtract the two, and solve for n:
        # n = (abc - ab) / (10^len(b + c) - 10^len(b))
        frac, repfrac = frac.split("(")
        repfrac = repfrac[:-1]

        iintp = int(intp)
        ifrac = int(frac) if len(frac) > 0 else 0
        irep = int(repfrac)

        return (
            (iintp * (10 ** (len(frac + repfrac))) + ifrac * 10 ** len(repfrac) + irep) - (iintp * 10 ** len(frac) + ifrac),
            (10** len(frac+repfrac) - 10 **len(frac))
        )
    ```