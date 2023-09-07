# Runtime: 50 ms (Top 25.7%) | Memory: 16.17 MB (Top 90.4%)

class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        return max(accumulate([0]+gain))