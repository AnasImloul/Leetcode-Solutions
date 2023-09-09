# Runtime: 84 ms (Top 36.7%) | Memory: 16.24 MB (Top 100.0%)










class Solution:
  def xorGame(self, nums: List[int]) -> bool:
    return functools.reduce(operator.xor, nums) == 0 or len(nums) % 2 == 0
