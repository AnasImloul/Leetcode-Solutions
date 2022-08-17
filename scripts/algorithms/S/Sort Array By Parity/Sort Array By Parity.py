class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        # transverse nums
        # if nums[i] is even
        # put it in first index(l) and increase l+=1
        #if nums[i] is not even keep increasing second pointer
        l =0
        r = 0
        for i in range(len(nums)):
            if nums[i] % 2 == 0:
                nums[l], nums[r] = nums[i], nums[l]
                l+=1
            r+=1
        return nums
