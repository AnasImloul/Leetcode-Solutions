class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        l,r = 0, len(nums)-1
        pointer = 0
        arr = [0] *len(nums)
        pointer = r
        while l<=r:
            if abs(nums[r]) > abs(nums[l]):
                arr[pointer] = nums[r] **2
                r-=1
                pointer-=1
            else:
                arr[pointer] = nums[l] **2
                l+=1
                pointer-=1
                
            
        return arr
            
            
            
