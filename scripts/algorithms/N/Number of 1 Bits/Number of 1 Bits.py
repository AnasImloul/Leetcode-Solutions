# Runtime: 27 ms (Top 98.51%) | Memory: 13.8 MB (Top 50.40%)
class Solution:
    def hammingWeight(self, n: int) -> int:
      i = 0
      while n > 0:
        if n % 2 != 0: i += 1
        n = n >> 1
      return i