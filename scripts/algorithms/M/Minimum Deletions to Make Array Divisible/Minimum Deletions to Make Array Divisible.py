# Runtime: 1147 ms (Top 45.35%) | Memory: 25.8 MB (Top 79.68%)
class Solution:
    def minOperations(self, nums: List[int], divs: List[int]) -> int:
        div = reduce(gcd, divs)
        return next((i for i, n in enumerate(sorted(nums)) if div % n == 0), -1)