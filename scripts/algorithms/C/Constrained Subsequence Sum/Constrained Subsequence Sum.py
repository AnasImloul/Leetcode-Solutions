# Runtime: 1386 ms (Top 69.5%) | Memory: 30.16 MB (Top 58.7%)

class Solution:
    def constrainedSubsetSum(self, nums: List[int], k: int) -> int:
        deque = []
        for i, num in enumerate(nums):
                
            while(deque and deque[0] < i - k): # delete that didn't end with a number in A[i-k:i]
                deque.pop(0)
                
            if deque:  # compute the max sum we can get at index i
                nums[i] = nums[deque[0]] + num
            
            while(deque and nums[deque[-1]] < nums[i]): 
                # delet all the sequence that smaller than current sum, becaus there will never be
                # considers ==> smaller than current sequence, and end before current sequence
                deque.pop()
                
            if nums[i] > 0: # if nums[i] < 0, it can't be a useful prefix sum    
            	deque.append(i)
        
        return max(nums)