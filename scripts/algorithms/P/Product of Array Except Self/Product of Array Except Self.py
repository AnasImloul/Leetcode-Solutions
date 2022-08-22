# Runtime: 477 ms (Top 13.75%) | Memory: 22.5 MB (Top 18.46%)
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        pre = [1]* (len(nums)+1)
        back = [1]*(len(nums)+1)

        for i in range(len(nums)):
            pre[i+1] = pre[i]*nums[i]

        for i in range(len(nums)-1,-1,-1):
            back[i-1] = back[i]*nums[i]
        for i in range(len(pre)-1):
            nums[i]=pre[i]*back[i]

        return nums