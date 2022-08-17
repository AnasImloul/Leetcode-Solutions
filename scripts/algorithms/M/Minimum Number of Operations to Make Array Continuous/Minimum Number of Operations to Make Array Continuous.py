class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        nums = sorted(set(nums))
        end = 0
        ans = -1
        for i in range(len(nums)):
            while end < len(nums):
                if nums[i] + n > nums[end]:
                    end+=1
                else:
                    break
            ans = max(ans,end - i)
        return n - ans
