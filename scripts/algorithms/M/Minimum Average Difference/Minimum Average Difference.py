from itertools import accumulate

class Solution:
    def minimumAverageDifference(self, nums: List[int]) -> int:
        size = len(nums)

        nums[::] = list(accumulate(nums))
        total = nums[-1]
        
        min_tuple = [0, sys.maxsize]
        
        for (i, n) in enumerate(nums):
            i = i + 1
            avg_i = floor(n/i)
            
            diff = size - i
            total_avg = floor((total - n) / (diff if diff>0 else 1))

            avg = abs( avg_i - total_avg) 
            if min_tuple[1] > avg:
                min_tuple[1] = avg
                min_tuple[0] = i - 1
            
        return min_tuple[0]
