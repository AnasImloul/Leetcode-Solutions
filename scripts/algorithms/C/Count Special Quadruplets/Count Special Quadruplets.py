# Runtime: 640 ms (Top 64.4%) | Memory: 17.10 MB (Top 9.2%)

class Solution:
    def countQuadruplets(self, nums: List[int]) -> int:
        return sum([1 for a, b, c, d in combinations(nums, 4) if a + b + c == d])