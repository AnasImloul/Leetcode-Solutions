# Runtime: 1523 ms (Top 9.74%) | Memory: 34 MB (Top 8.51%)
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:

        dictx = {}

        for each in nums:
            if each not in dictx:
                dictx[each] = 1
            else:
                return each
