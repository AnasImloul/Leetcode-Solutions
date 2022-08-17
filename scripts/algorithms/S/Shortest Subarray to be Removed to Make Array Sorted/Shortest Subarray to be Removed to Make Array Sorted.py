class Solution:
    def findLengthOfShortestSubarray(self, arr: List[int]) -> int:
        n = len(arr)
        i = 0
        while i < n-1 and arr[i+1] >= arr[i]:
            i += 1
        
        if i == n-1:
            return 0
        
        j = n-1
        while j >= 0 and arr[j-1] <= arr[j]:
            j -= 1
        
        ans = min(n, n-i-1, j)
        
        for l in range(i+1):
            r = j
            while r < n and arr[r] < arr[l]:
                r += 1
            ans = min(ans, r-l-1)
        
        return ans