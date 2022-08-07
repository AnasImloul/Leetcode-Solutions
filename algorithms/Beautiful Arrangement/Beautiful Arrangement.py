class Solution:
    def count(self, i, n, used):
        if i > n:
            return 1
        ctr = 0
        for j in range(1, n + 1):
            if j not in used and (j % i == 0 or i % j == 0):
                ctr += self.count(i + 1, n, used.union({j}))
        return ctr
    
    def countArrangement(self, n: int) -> int:
        return self.count(1, n, set())
