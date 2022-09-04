# Runtime: 1881 ms (Top 9.44%) | Memory: 23.9 MB (Top 80.86%)
from functools import lru_cache, cache

class Solution:
    def maximumANDSum(self, nums: List[int], numSlots: int) -> int:
        @cache
        def dp(i=0, m1=0, m2=0): # mask1, mask2
            if i == len(nums):
                return 0
            ans = 0
            for s in range(numSlots):
                if m2 & (1 << s) == 0: # i.e. 0b0?, implying the slot is not full
                    if m1 & (1 << s) == 0: # 0b00 + 1 => 0b01
                        nm1 = m1 | (1 << s); nm2 = m2
                    else: # 0b01 + 1 => 0b10
                        nm1 = m1 & ~(1 << s); nm2 = m2 | (1 << s)
                    ans = max(ans, dp(i + 1, nm1, nm2) + ((s + 1) & nums[i])) # s + 1 is the actual slot no.
            return ans
        return dp()