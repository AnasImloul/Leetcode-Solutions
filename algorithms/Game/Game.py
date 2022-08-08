class Solution:
    def judgePoint24(self, cards: List[int]) -> bool:
        return self.allComputeWays(cards, 4, 24)
        
    def allComputeWays(self, nums, l, target):
        if l == 1:
            if abs(nums[0] - target) <= 1e-6:
                return True
            return False
        for first in range(l):
            for second in range(first + 1, l):
                tmp1, tmp2 = nums[first], nums[second]
                nums[second] = nums[l - 1]
                
                nums[first] = tmp1 + tmp2
                if self.allComputeWays(nums, l - 1, target):
                    return True
                nums[first] = tmp1 - tmp2
                if self.allComputeWays(nums, l - 1, target):
                    return True
                nums[first] = tmp2 - tmp1
                if self.allComputeWays(nums, l - 1, target):
                    return True
                nums[first] = tmp1 * tmp2
                if self.allComputeWays(nums, l - 1, target):
                    return True
                if tmp2:
                    nums[first] = tmp1 / tmp2
                    if self.allComputeWays(nums, l - 1, target):
                        return True
                if tmp1:
                    nums[first] = tmp2 / tmp1
                    if self.allComputeWays(nums, l - 1, target):
                        return True
                nums[first], nums[second] = tmp1, tmp2
        return False