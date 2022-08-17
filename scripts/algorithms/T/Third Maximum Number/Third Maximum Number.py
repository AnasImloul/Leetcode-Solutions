class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        nums_set = set(nums)
        sorted_set = sorted(nums_set)
        return sorted_set[-3] if len(nums_set) >2 else sorted_set[-1]
    
    
            #use set() to remove dups
            #if len of nums after dups have been removed is at least 2, a third max val must exist
            #if not, just return the max
        
        
        #you can do it in 1 line like this but then you have to call the same functions repeatedly
        #return sorted(set(nums))[-3] if len(set(nums)) > 2  else sorted(set(nums))[-1]
    
 
    
