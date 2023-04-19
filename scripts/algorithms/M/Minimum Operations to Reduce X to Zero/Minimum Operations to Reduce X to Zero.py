class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        start =0
        end = len(nums)-1
        totalsum = sum(nums)
        check = 0
        windowlen =0
        s = totalsum - x # s in case1 = 11-5 =6
        if totalsum<x:
            return -1
        if sum(nums) ==x:
            return len(nums)

        for end in range(len(nums)):
            check += nums[end]
            while check > s:
                check -= nums[start]
                start +=1
            if check ==s:
                windowlen = max(windowlen,end-start+1)
        if windowlen !=0:
            return len(nums)-windowlen
        else:
            return -1        