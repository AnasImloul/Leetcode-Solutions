class Solution:
    def soupServings(self, n: int) -> float:
        @cache                                 # cache the result for input (a, b)
        def dfs(a, b):
            if a <= 0 and b > 0: return 1      # set criteria probability
            elif a <= 0 and b <= 0: return 0.5
            elif a > 0 and b <= 0: return 0
            return (dfs(a-4, b) + dfs(a-3, b-1) + dfs(a-2, b-2) + dfs(a-1, b-3)) * 0.25 # dfs
        if n > 4275: return 1                  # observe the distribution you will find a tends to be easier to get used up than b
        n /= 25                                # reduce the input scale
        return dfs(n, n)                       # both soup have n ml