# Runtime: 35 ms (Top 88.02%) | Memory: 14.1 MB (Top 5.79%)
"""
approach:
first replace - with +- in the string so that implementation gets
a little easy
"""
class Solution:
    def fractionAddition(self, expression: str) -> str:
        expression = expression.replace('-', '+-')
        parts = [item for item in expression.split('+') if item != '']
        numes, denoms, denom_set, lcm = [], [], set(), 1
        def get_lcm(a, b):
            if a == 1:
                return b
            if b == 1:
                return a
            if a < b:
                if b % a == 0:
                    return a * get_lcm(1, b/a)
                else:
                    return a * get_lcm(1, b)
            else:
                if a % b == 0:
                    return b * get_lcm(a/b, 1)
                else:
                    return b * get_lcm(a, 1)

        for part in parts:
            num, den = part.split('/')
            numes.append(int(num))
            denoms.append(int(den))
            lcm = get_lcm(lcm, int(den))

        result = 0
        for num, den in zip(numes, denoms):
             result +=num * int(lcm/den)

        def get_gcd(a, b):
            if a == 0:
                return b
            if b == 0:
                return a
            if a == b:
                return a
            elif a < b:
                return get_gcd(a, b-a)
            else:
                return get_gcd(a-b, b)

        gcd = get_gcd(abs(result), lcm)
        return str(int(result/gcd)) + '/' + str(int(lcm/gcd))