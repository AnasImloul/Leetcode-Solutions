# Runtime: 0 ms (Top 100.00%) | Memory: 19.10 MB (Top 90.41%)

class Solution:
    def smallestEvenMultiple(self, n: int) -> int:
        return n if n % 2 ==0 else n * 2
