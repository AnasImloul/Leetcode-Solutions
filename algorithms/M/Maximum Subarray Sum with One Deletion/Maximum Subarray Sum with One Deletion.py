class Solution:
    def maximumSum(self, arr: List[int]) -> int:
        
        if len(arr) == 1:
            return arr[0]
        
		# max sum of subarray that includes current and is continuous
        on_0, on_1 = arr[0], max(0, arr[0]) + arr[1] 
		# max sum of subarray that includes current and isn't noncontinuous
        off_0, off_1 = float('-inf'), float('-inf') 
		
        ans = max(on_0, on_1, off_0, off_1) # intial ans
		
        p = 2 
        while p < len(arr):
            
            on_0, on_1, off_0, off_1 = on_1, max(on_1 + arr[p], arr[p]), off_1, max(on_0 + arr[p], off_1 + arr[p])
            ans = max(ans, on_1, off_1) # update ans
            
            p += 1

        return  ans
