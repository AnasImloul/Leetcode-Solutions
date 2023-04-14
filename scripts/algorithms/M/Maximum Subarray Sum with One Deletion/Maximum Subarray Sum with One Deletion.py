class Solution:
    def maximumSum(self, arr: List[int]) -> int:
        n = len(arr)
        if n ==1:
            return arr[0]
        dpLeft = [-10**4-1 for _ in range(n)]
        dpLeft[0] = arr[0]
        i = 1 
        while i < n :
            dpLeft[i] = max(arr[i],dpLeft[i-1]+arr[i])
            i += 1
        dpRight = [-10**4-1 for _ in range(n)]
        dpRight[-1] = arr[-1]
        j = n-2 
        while j >= 0:
            dpRight[j] = max(arr[j],dpRight[j+1]+arr[j])
            j -= 1
        k = 0
        maxi = -10**4-1
        while k < n:
            # if we take it 
            curr_maxi_with = dpRight[k] + dpLeft[k] - arr[k]
            
            if k==0:
                curr_maxi_without = dpRight[k+1]
            elif k==n-1:
                curr_maxi_without = dpLeft[k-1]
            else:
                if dpLeft[k-1]>=0 and dpRight[k+1]>=0:
                    curr_maxi_without = dpRight[k+1] + dpLeft[k-1]
                else:
                    curr_maxi_without = max(dpLeft[k-1],dpRight[k+1])
            
            maxi= max(maxi,curr_maxi_without, curr_maxi_with)
            k += 1
        
        return maxi 

