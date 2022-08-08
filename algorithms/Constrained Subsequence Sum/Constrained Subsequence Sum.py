class Solution:
    def constrainedSubsetSum(self, nums: List[int], k: int) -> int:
        
        res = nums[0]
        hq = [(-nums[0], 0)] # (-dp[j],j) dp[j]: maximum sum until index j including nums[j]  
        
        for j, num in enumerate(nums[1:], start = 1):
    
            while hq and hq[0][1] < j-k: heapq.heappop(hq)
                
            cur = max(-hq[0][0], 0) + num
            heapq.heappush(hq,(-cur,j))
            res = max(res,cur)

        return res
