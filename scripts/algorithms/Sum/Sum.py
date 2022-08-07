class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        
        if len(nums) < 4: return []
        
        nums.sort()
        res = []
        
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                l = j+1
                r = len(nums)-1
                while l < r:

                    sum_ = nums[i]+nums[j]+nums[l]+nums[r]
                    a = [nums[i], nums[j], nums[l], nums[r]]
                
                    if sum_ == target and a not in res:
                        res.append(a)
                  
                    if sum_ > target:
                        r -= 1
                    
                    else:
                        l += 1
                        while l < r and nums[l-1] == nums[l]:
                            l += 1
                  
        return res
        
        # An Upvote will be encouraging
                    
        
