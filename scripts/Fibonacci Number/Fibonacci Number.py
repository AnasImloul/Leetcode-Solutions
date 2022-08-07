class Solution:
    def fib(self, n: int) -> int:
        fa = [0, 1]
        
        for i in range(2, n + 1):
            fa.append(fa[i-2] + fa[i-1])
        
        return fa[n]
