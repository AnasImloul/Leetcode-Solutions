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
