class Solution():
    def atMostNGivenDigitSet(self, digits, n):
        cache = {}
        target = str(n)

        def helper(idx, isBoundary, isZero):
            if idx == len(target): return 1
            if (idx, isBoundary, isZero) in cache: return cache[(idx, isBoundary, isZero)]
            
            res = 0
            if isZero and idx != len(target)-1:
                res+= helper(idx+1, False, True)
            for digit in digits:
                if isBoundary and int(digit) > int(target[idx]): continue
                res+= helper(idx+1, True if isBoundary and digit == target[idx] else False, False)

            cache[(idx, isBoundary, isZero)] = res
            return res

        return helper(0, True, True)