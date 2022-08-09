# max absolte diff within a subarray is subarray max substracted by subarray min
class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        q = collections.deque() # monotonic decreasing deque to compute subarray max, index of
        q2 = collections.deque() # monotonic increasing deque to compute subarray min, index of
        
        # sliding window
        res = left = 0
        for right in range(len(nums)):
            # pop monotocity-violating numbers from right end
            while q and nums[q[-1]] <= nums[right]:
                q.pop()
            q.append(right)
            
            # pop monotocity-violating numbers from right end
            while q2 and nums[q2[-1]] >= nums[right]:
                q2.pop()
            q2.append(right)
            
            # sliding window
            while left < right and q and q2 and nums[q[0]] - nums[q2[0]] > limit:
                # compress window from left pointer
                if q and q[0] == left:
                    q.popleft()
                
                # compress left pointer
                if q2 and q2[0] == left:
                    q2.popleft()
                    
                left += 1
            
            if nums[q[0]] - nums[q2[0]] <= limit:
                res = max(res, right - left + 1)
        
        return res
