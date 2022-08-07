from collections import defaultdict
class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        sign = "" if numerator*denominator >= 0 else "-"
        numerator, denominator = abs(numerator), abs(denominator)
        a = numerator//denominator
        numerator %= denominator
        if not numerator: return sign+str(a)
        fractions = []
        index = defaultdict(int)
        while 10*numerator not in index:
            numerator *= 10
            index[numerator] = len(fractions)
            fractions.append(str(numerator//denominator))
            numerator %= denominator
        i = index[10*numerator]
        return sign+str(a)+"."+"".join(fractions[:i])+"("+"".join(fractions[i:])+")" if numerator else sign+str(a)+"."+"".join(fractions[:i])