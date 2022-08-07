import bisect

class Solution:
    
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        
        half = int(k / 2)
        
        if k % 2 == 0:
            i, j = half - 1, half + 1
        else:
            i, j = half, half + 1
        
        def median(l, i, j):
            return sum(l[i:j])/len(l[i:j])
        
        digits = nums[:k]
        digits.sort()
        
        result = [median(digits, i, j)]
            
        for q in range(k, len(nums)):
            
            digits.remove(nums[q - k])
            bisect.insort(digits, nums[q])
            result.append(median(digits, i, j))   
            
        return result
