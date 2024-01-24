// Runtime: 55 ms (Top 93.08%) | Memory: 16.50 MB (Top 58.13%)

class Solution:
    def sumOfSquares(self, nums: List[int]) -> int:
        
        return sum([num*num for index, num in enumerate(nums) if len(nums) % (index+1) == 0])
