# Runtime: 132 ms (Top 5.33%) | Memory: 13.9 MB (Top 32.60%)
class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        return max(map(sum, accounts))