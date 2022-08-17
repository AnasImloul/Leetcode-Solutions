class Solution:
    def minSubsequence(self, nums: List[int]) -> List[int]:
        nums.sort(reverse=True)
        val = sum(nums)
        temp = []
        for i in range(len(nums)):
            temp.append(nums[i])
            if sum(temp)>val-sum(temp):
                return temp
            
