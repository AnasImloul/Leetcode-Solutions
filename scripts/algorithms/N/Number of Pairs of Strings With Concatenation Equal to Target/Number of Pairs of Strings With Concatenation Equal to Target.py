class Solution:
    def numOfPairs(self, nums, target):
        return sum(i + j == target for i, j in permutations(nums, 2))
