# Runtime: 58 ms (Top 23.2%) | Memory: 16.30 MB (Top 28.6%)

class Solution:
    def specialArray(self, nums: List[int]) -> int:
        nums.sort()
        for i in range(max(nums)+1):
            y=len(nums)-bisect.bisect_left(nums,i)
            if y==i:
                return i
        return -1

        
        