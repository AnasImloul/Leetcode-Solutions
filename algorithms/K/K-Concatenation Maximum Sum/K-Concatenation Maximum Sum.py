class Solution:
    def kConcatenationMaxSum(self, arr: List[int], k: int) -> int:
        
        dp = [0] * len(arr) # sum of the best subarry ends at i
        dp[0] = arr[0]
        total = arr[0] # total sum 
        right = arr[0] # sum of the best subarray starts at 0
        
        p = 1 
        while p < len(arr):
            dp[p] = max(arr[p], dp[p-1] + arr[p])
            total += arr[p] 
            right = max(right, total)
            
            p += 1
        
        isolated = max(dp + [0]) # max sum
        left = dp[-1] # sum of the best subarray ends at n-1
        
        if k == 1:
            
            return isolated  % (10**9 + 7)
        
        return max(left + right + max(0,(k-2) * total), isolated) % (10**9 + 7)
