class Solution:
    def makeArrayIncreasing(self, arr1: List[int], arr2: List[int]) -> int:
        n1 , n2, dp = len(arr1) , len(arr2) , {}
        arr2.sort()
        
        def solve(i , j , prev):
            
            if i == n1:return 0
            
            if (i,j,prev) in dp: return dp[(i,j,prev)]
            
            k = bisect.bisect_right(arr2[j:],prev) + j
        
            ans = float('inf') if k == n2 else solve(i+1,k+1,arr2[k]) + 1
            
            if arr1[i] > prev:ans = min(ans,solve(i+1 , j ,arr1[i]))
            
            dp[(i,j,prev)] = ans
            
            return ans
        
        
        ans = solve(0,0,-float('inf'))
        
        return ans if ans != float('inf') else -1