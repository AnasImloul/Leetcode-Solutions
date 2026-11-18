# Runtime: 2 ms (Top 84.02%) | Memory: 19.10 MB (Top 90.57%)

class Solution:
    def numberOfPoints(self, nums: List[List[int]]) -> int:
        return len(set(j for i in nums for j in range(i[0], i[1] + 1)))
