# Runtime: 46 ms (Top 80.68%) | Memory: 13.8 MB (Top 55.21%)
class Solution:
    def fib(self, n: int) -> int:
        fa = [0, 1]

        for i in range(2, n + 1):
            fa.append(fa[i-2] + fa[i-1])

        return fa[n]