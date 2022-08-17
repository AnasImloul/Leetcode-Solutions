class Solution:
    def getStrongest(self, arr: List[int], k: int) -> List[int]:
        n = len(arr)
        medInd = (n-1)//2
        arr = sorted(arr)
        med = arr[medInd]
        
        start, end = 0, n-1
        ans = []
        while start <= end and len(ans) < k:
            if abs(med - arr[end]) < abs(med - arr[start]):
                ans.append(arr[start])
                start += 1
            else:# abs(med - arr[end]) >= abs(med - arr[start]):
                # <= because end is always bigger in a sorted array
                ans.append(arr[end])
                end -= 1
        
        return ans
