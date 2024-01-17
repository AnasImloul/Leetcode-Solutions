// Runtime: 37 ms (Top 76.06%) | Memory: 17.40 MB (Top 35.12%)

class Solution:
    def twoEggDrop(self, n: int) -> int:
        return ceil(((1+n*8)**0.5-1)/2)
