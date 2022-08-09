class Solution(object):
    def threeSum(self, nums):
        ans = []
        nums.sort()
        
        for i in range(len(nums)):
            if nums[i] > 0: break  # after sorting, if the min > 0, we couldn't find such three values
            if i > 0 and nums[i] == nums[i - 1]:  # ensure that nums[i] is not duplicated
                continue               
            l, r = i + 1, len(nums) - 1
            while l < r:
                if nums[l] + nums[r] > -nums[i]:
                    r -= 1
                elif nums[l] + nums[r] < -nums[i]:
                    l += 1
                else:
                    ans.append([nums[i], nums[l], nums[r]])
					# update l to get a different sum
                    l += 1
                    while nums[l] == nums[l - 1] and l < r:
                        l += 1
        return ans
