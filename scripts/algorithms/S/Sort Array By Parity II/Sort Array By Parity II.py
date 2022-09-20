# Runtime: 608 ms (Top 6.36%) | Memory: 16.7 MB (Top 25.83%)
class Solution:
    def sortArrayByParityII(self, nums: List[int]) -> List[int]:
        arr = [None]*len(nums)
        even,odd = 0,1
        for i in(nums):
            if i % 2 == 0:
                arr[even] = i
                even +=2
        for i in (nums):
            if i % 2 != 0:
                arr[odd] = i
                odd+=2
        return arr