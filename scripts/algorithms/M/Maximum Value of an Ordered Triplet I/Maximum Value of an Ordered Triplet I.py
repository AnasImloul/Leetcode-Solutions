# Runtime: 0 ms (Top 100.00%) | Memory: 19.30 MB (Top 46.15%)

class Solution:
    def maximumTripletValue(self, nums: List[int], mx = 0) -> int:

        pref = accumulate(nums, max)
        suff = list(accumulate(nums[::-1], max))[::-1]

        return max(0,*((J-I) * K for I, J, K 
                                  in zip(nums[1:],pref,suff[2:])))
