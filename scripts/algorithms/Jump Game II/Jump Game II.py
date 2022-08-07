class Solution(object):
    def jump(self, nums):
        ans = l = r = 0
        
        while r < len(nums) -  1: 
            farthestJump = 0
			
            for i in range(l, r + 1):
                farthestJump = max(farthestJump, i + nums[i])
            
            l = r + 1
            r = farthestJump
            ans += 1
            
        return ans
