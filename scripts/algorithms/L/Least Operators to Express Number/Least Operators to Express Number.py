# Runtime: 3027 ms (Top 7.32%) | Memory: 13.9 MB (Top 97.56%)
class Solution(object):
    def leastOpsExpressTarget(self, x, target):
        return self.cost(x, target)

    def cost(self, x, val):
        if val == x:
            return 0
        elif val < x:
            # two possible states
            # either val > x / 2: we substract 1s
            state_1 = 2 * (x - val)
            # or val < x / 2: we divide once to 1 and we add enough 1s
            state_2 = 2*val - 1
            return min(state_1, state_2)
        else:
            # there is a maximum power of x that we can add
            p = int(log(val) // log(x))
            # and either x^p or x^(p+1) is the closest
            a = x**p
            b = a*x
            if b < 2*val:
                # x**(p+1) - val < val - x**p
                return min(p + self.cost(x, val - a), p + 1 + self.cost(x, b - val))
            else:
                return p + self.cost(x, val - a)