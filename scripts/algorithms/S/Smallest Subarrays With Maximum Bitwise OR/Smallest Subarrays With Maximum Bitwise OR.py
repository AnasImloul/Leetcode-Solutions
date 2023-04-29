class Solution:
    def smallestSubarrays(self, nums: List[int]) -> List[int]:
        # two sweeps
        len_n = len(nums)
        # sweep 1: find the maximum OR value at each index
        max_or = [0] * len_n
        idx, c_or = len_n - 1, 0
        while idx >= 0:
            c_or |= nums[idx]
            max_or[idx] = c_or
            idx -= 1
        
        # sweep 2: starting from the last number, track the closest index for every bit
        ans = [1] * len_n
        bidx = [None] * 32
        idx = len_n - 1
        while idx >= 0:
            i = 0
            n = nums[idx]
            while n:
                if n & 1:
                    bidx[i] = idx
                i += 1
                n >>= 1
            mor = max_or[idx]
            max_dist, i = 1, 0
            while mor:
                if mor & 1:
                    max_dist = max(max_dist, bidx[i] - idx + 1)
                i += 1
                mor >>= 1
            ans[idx] = max_dist
            idx -= 1
            
        return ans