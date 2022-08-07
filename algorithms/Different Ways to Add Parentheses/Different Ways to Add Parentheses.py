from functools import cache
class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        @cache
        def dfs(s):
            if s.isdigit():
                return [int(s)]
            res = []
            for i, c in enumerate(s):
                if c in "+-*":
                    left = dfs(s[:i])
                    right = dfs(s[i+1:])
                    res.extend(eval(str(x)+c+str(y)) for x in left for y in right)
            return res
        return dfs(expression)