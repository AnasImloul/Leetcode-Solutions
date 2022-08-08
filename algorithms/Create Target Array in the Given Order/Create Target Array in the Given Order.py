class Solution:
    def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:
        
        out = [] 
        for num, idx in zip(nums, index):
            
            if len(out) <= idx:
                out.append(num)
                
            else:
                out.insert(idx, num)
                
        return out
