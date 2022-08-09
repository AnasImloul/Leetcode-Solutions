M = 10 ** 9 + 7

from functools import cache

class Solution:
    def rearrangeSticks(self, n: int, k: int) -> int:
        return dp(n, k)

# consider the shortest
@cache
def dp(n, k):
    if n == k:
        return 1
    if n <= 0 or k <= 0:
        return 0
    return (dp(n - 1, k - 1) + (n - 1) * dp(n - 1, k)) % M  

# `dp(n, k)` indicates the number of arrangements of `n` distinct sticks with exactly `k` visible sticks. 
# Those `n` **distinct** sticks does NOT have to be numbered from `1` to `n` consecutively.
