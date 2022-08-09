class Solution:
    def minOperations(self, nums: List[int], divs: List[int]) -> int:
        div = reduce(gcd, divs)
        return next((i for i, n in enumerate(sorted(nums)) if div % n == 0), -1)
