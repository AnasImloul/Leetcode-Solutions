class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        
        dictx = {}
        
        for each in nums:
            if each not in dictx:
                dictx[each] = 1
            else:
                return each
        
