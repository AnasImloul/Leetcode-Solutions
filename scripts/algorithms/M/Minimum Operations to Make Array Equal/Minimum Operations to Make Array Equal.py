class Solution:
    def minOperations(self, n: int) -> int:
        return n*(n//2)-(n//2)**2
