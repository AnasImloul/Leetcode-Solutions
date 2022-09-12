# Runtime: 1728 ms (Top 12.88%) | Memory: 16.4 MB (Top 8.29%)
class Solution:
    def distributeCandies(self, candyType: List[int]) -> int:
        return min(len(set(candyType)), (len(candyType)//2))