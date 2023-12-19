// Runtime: 631 ms (Top 77.84%) | Memory: 30.70 MB (Top 96.45%)

class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        
        res, cur, pos, dup = 0, 0, [-1] * 100001, -1
        
        for i in range(0,len(nums)):
            cur += nums[i]                      # compute running sum for
            if i >= k: cur -= nums[i-k]         # the window of length k
            
            dup = max(dup, pos[nums[i]])        # update LAST seen duplicate
            
            if i - dup >= k:                    # if no duplicates were found
                res = max(res, cur)             # update max window sum

            pos[nums[i]] = i

        return res
