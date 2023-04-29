class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        wstart = wsum = count = 0
        
        for wend in range(len(arr)):
            wsum += arr[wend]
            
            if wend >= k:
                wsum -= arr[wstart]
                wstart += 1
            if (wsum//k) >= threshold and (wend-wstart+1) == k: 
                count += 1
        return count