class Solution:
    def maxProductDifference(self, nums: List[int]) -> int:
        max_1 = 0
        max_2 = 0
        min_1 = 10001
        min_2 = 10001
        for i in nums:
            if i >= max_1:
                max_2,max_1 = max_1,i
            elif i > max_2:
                max_2 = i
            if i <= min_1:
                min_2,min_1 = min_1,i
            elif i < min_2:
                min_2 = i
            
        return max_1*max_2 - min_1*min_2
