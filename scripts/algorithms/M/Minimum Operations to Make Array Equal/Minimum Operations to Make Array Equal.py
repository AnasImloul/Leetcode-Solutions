class Solution:
    def minOperations(self, n: int) -> int:

        return sum([n-x for x in range(n) if x % 2 != 0])